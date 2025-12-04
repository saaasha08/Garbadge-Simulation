#include <graphics.h>  // গ্রাফিক্স লাইব্রেরি ইমপোর্ট
#include <stdlib.h>    // সাধারণ ফাংশন যেমন rand() ইত্যাদির জন্য
#include <stdio.h>     // printf, sprintf ইত্যাদির জন্য
#include <time.h>      // সময় সম্পর্কিত ফাংশনের জন্য
#include <conio.h>     // getch() ও কীবোর্ড ইনপুটের জন্য

#define SCREEN_WIDTH 1000   // স্ক্রিনের প্রস্থ
#define SCREEN_HEIGHT 600   // স্ক্রিনের উচ্চতা
#define GARBAGE_SIZE 40     // আবর্জনার সাইজ
#define BIN_WIDTH 100       // বিনের প্রস্থ
#define BIN_HEIGHT 100      // বিনের উচ্চতা
#define GAME_TIME 30        // খেলায় মোট সময় (সেকেন্ডে)
#define MAX_GARBAGE 4       // একসাথে সর্বাধিক আবর্জনার সংখ্যা
#define FALL_SPEED 4.0      // আবর্জনা পতনের গতি

// 🔹 আবর্জনার ধরন
enum GarbageType { PAPER, PLASTIC, FOOD };

// 🔹 ফলের ধরন (যদি FOOD টাইপ হয়)
enum FruitType { APPLE, BANANA, MANGO };

// 🔹 আবর্জনার স্ট্রাকচার
struct Garbage {
    float x, y;             // x, y অবস্থান
    GarbageType type;       // ধরণ: PAPER / PLASTIC / FOOD
    FruitType fruitType;    // যদি FOOD হয়, ফলের ধরন
};

// 🔹 বিনের স্ট্রাকচার
struct Bin {
    int x;                  // বিনের x অবস্থান
    GarbageType type;       // ধরণ: PAPER / PLASTIC / FOOD
};

// 🔹 গ্লোবাল ভেরিয়েবল
Garbage garbages[MAX_GARBAGE]; // আবর্জনার অ্যারে
Bin bins[3];                    // তিনটি বিনের অ্যারে
int score = 0;                  // স্কোর
time_t startTime;               // গেম শুরু হওয়ার সময়
int draggingBin = -1;           // কোন বিন ড্র্যাগ করা হচ্ছে
int prevMouseX = 0;             // মাউসের পূর্বের x অবস্থান

// 🔹 আকাশ ও ঘাসের ব্যাকগ্রাউন্ড আঁকা
void drawSkyBackground() {
    setfillstyle(SOLID_FILL, COLOR(135,206,235)); // আকাশের নীল রঙ
    bar(0,0,SCREEN_WIDTH,SCREEN_HEIGHT);          // পুরো স্ক্রিন আকাশে ভরানো
    setfillstyle(SOLID_FILL, COLOR(34,139,34));   // ঘাসের রঙ
    bar(0, SCREEN_HEIGHT-50, SCREEN_WIDTH, SCREEN_HEIGHT); // নিচের ঘাস
}

// 🔹 বিনগুলো ইনিশিয়ালাইজ করা
void initBins() {
    bins[0] = {150, PAPER};    // প্রথম বিন
    bins[1] = {400, PLASTIC};  // দ্বিতীয় বিন
    bins[2] = {650, FOOD};     // তৃতীয় বিন
}

// 🔹 একটি বিন আঁকা
void drawBin(int x, const char *label, int color) {
    setfillstyle(SOLID_FILL, color);  // পূরণের রঙ
    int shape[] = {                   // বিনের পলিগন কো-অর্ডিনেট
        x+20, SCREEN_HEIGHT-BIN_HEIGHT,
        x+BIN_WIDTH-20, SCREEN_HEIGHT-BIN_HEIGHT,
        x+BIN_WIDTH, SCREEN_HEIGHT,
        x, SCREEN_HEIGHT
    };
    fillpoly(4, shape);               // পলিগন আঁকা
    setcolor(WHITE);                   // লেখা রঙ
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2); // ফন্ট সেট করা
    outtextxy(x + 15, SCREEN_HEIGHT - BIN_HEIGHT - 30, (char*)label); // লেবেল লেখা
}

// 🔹 সব বিন একসাথে আঁকা
void drawBins() {
    drawBin(bins[0].x, "PAPER", COLOR(0,150,0));
    drawBin(bins[1].x, "PLASTIC", WHITE);
    drawBin(bins[2].x, "FOOD", COLOR(255,0,0));
}

// 🔹 একটি আবর্জনা ইনিশিয়ালাইজ করা
void initGarbage(int i) {
    garbages[i].x = rand() % (SCREEN_WIDTH - GARBAGE_SIZE); // এলোমেলো x
    garbages[i].y = -(rand() % 300);                        // উপরের থেকে এলোমেলো y
    garbages[i].type = (GarbageType)(rand() % 3);          // এলোমেলো ধরন
    if (garbages[i].type == FOOD)
        garbages[i].fruitType = (FruitType)(rand() % 3);   // FOOD হলে ফল নির্ধারণ
}

// 🔹 PAPER আঁকা
void drawPaper(int x,int y) {
    setfillstyle(SOLID_FILL, COLOR(0,150,0));
    int sheet[] = {
        x, y,
        x+GARBAGE_SIZE, y,
        x+GARBAGE_SIZE, y+GARBAGE_SIZE,
        x, y+GARBAGE_SIZE
    };
    fillpoly(4, sheet);                        // পলিগন পূরণ
    setcolor(COLOR(0,100,0));
    rectangle(x+3,y+3,x+GARBAGE_SIZE-3,y+GARBAGE_SIZE-3); // আউটার রেক্টেঙ্গেল
    for (int i=y+6;i<y+GARBAGE_SIZE-3;i+=6)
        line(x+5,i,x+GARBAGE_SIZE-5,i);        // লাইন আঁকা
}

// 🔹 PLASTIC (বটল) আঁকা
void drawPlastic(int x,int y) {
    setfillstyle(SOLID_FILL, WHITE);
    int bottle[] = {
        x+15, y,
        x+GARBAGE_SIZE-15, y,
        x+GARBAGE_SIZE-12, y+GARBAGE_SIZE-10,
        x+12, y+GARBAGE_SIZE-10
    };
    fillpoly(4, bottle);                        // বটল বডি
    bar(x+GARBAGE_SIZE/2-5, y-10, x+GARBAGE_SIZE/2+5, y); // বটলের গলা
    setcolor(BLACK);
    rectangle(x+15, y, x+GARBAGE_SIZE-15, y+GARBAGE_SIZE-10);
    rectangle(x+GARBAGE_SIZE/2-5, y-10, x+GARBAGE_SIZE/2+5, y);
}

// 🔹 FOOD (APPLE/BANANA/MANGO) আঁকা
void drawFood(int x,int y,FruitType type) {
    switch(type) {
        case APPLE:
            setfillstyle(SOLID_FILL, COLOR(255,0,0)); // লাল আপেল
            fillellipse(x+GARBAGE_SIZE/2, y+GARBAGE_SIZE/2,
                        GARBAGE_SIZE/3, GARBAGE_SIZE/3);
            setcolor(COLOR(0,200,0));
            setlinestyle(SOLID_LINE,0,3);
            line(x+GARBAGE_SIZE/2, y+GARBAGE_SIZE/2-10,
                 x+GARBAGE_SIZE/2, y+GARBAGE_SIZE/2-25); // ডালের মতো লাইন
            setlinestyle(SOLID_LINE,0,1);
            break;

        case BANANA:
            setcolor(YELLOW);
            setfillstyle(SOLID_FILL, YELLOW);
            fillellipse(x + 20, y + 25, 15, 8); // বানোয়ার আকার
            setcolor(BLACK);
            arc(x + 20, y + 25, 200, 340, 15); // আর্ক
            break;

        case MANGO:
            setfillstyle(SOLID_FILL, COLOR(255,165,0));
            fillellipse(x+GARBAGE_SIZE/2, y+GARBAGE_SIZE/2,
                        GARBAGE_SIZE/3, GARBAGE_SIZE/2.8); // ম্যাঙ্গোর আকার
            setcolor(COLOR(0,150,0));
            line(x+GARBAGE_SIZE/2, y+GARBAGE_SIZE/2-12,
                 x+GARBAGE_SIZE/2, y+GARBAGE_SIZE/2-22); // ডাল
            break;
    }
}

// 🔹 আবর্জনা অনুযায়ী ফাংশন কল
void drawGarbage(Garbage g) {
    switch(g.type) {
        case PAPER:   drawPaper((int)g.x,(int)g.y); break;
        case PLASTIC: drawPlastic((int)g.x,(int)g.y); break;
        case FOOD:    drawFood((int)g.x,(int)g.y,g.fruitType); break;
    }
}

// 🔹 কোলিশন চেক করা
void checkCollision(Garbage &g) {
    if (g.y >= SCREEN_HEIGHT - BIN_HEIGHT - GARBAGE_SIZE/2) { // যদি নিচে পৌঁছায়
        for (int i=0;i<3;i++) {                                 // সব বিনের সাথে চেক
            if (g.x >= bins[i].x && g.x <= bins[i].x + BIN_WIDTH) {
                if (g.type == bins[i].type) score += 5;         // সঠিক বিনে গেলে +5
                else score--;                                   // ভুল হলে -1
                initGarbage(&g - garbages);                     // পুনঃইনিশিয়ালাইজ
                return;
            }
        }
        initGarbage(&g - garbages);                             // কোন বিনে না গেলে পুনঃইনিশিয়ালাইজ
    }
}

// 🔹 মাউস কন্ট্রোল (ড্র্যাগিং)
void handleMouse() {
    if (ismouseclick(WM_LBUTTONDOWN)) {                       // যদি লেফট ক্লিক
        int mx=mousex(), my=mousey();
        for (int i=0;i<3;i++) {                               // কোন বিনে ক্লিক
            if (mx>=bins[i].x && mx<=bins[i].x+BIN_WIDTH &&
                my>=SCREEN_HEIGHT-BIN_HEIGHT && my<=SCREEN_HEIGHT) {
                draggingBin=i; prevMouseX=mx; break;
            }
        }
        clearmouseclick(WM_LBUTTONDOWN);
    }
    else if (ismouseclick(WM_LBUTTONUP)) {                    // যদি ক্লিক ছাড়া
        draggingBin=-1;
        clearmouseclick(WM_LBUTTONUP);
    }
    if (draggingBin!=-1) {                                   // যদি ড্র্যাগ হচ্ছে
        int mx=mousex();
        bins[draggingBin].x += (mx - prevMouseX);            // বিনকে মুভ করা
        prevMouseX = mx;
        if (bins[draggingBin].x < 0) bins[draggingBin].x = 0;            // স্ক্রিনের বাইরে না যেতে দাও
        if (bins[draggingBin].x > SCREEN_WIDTH - BIN_WIDTH)
            bins[draggingBin].x = SCREEN_WIDTH - BIN_WIDTH;
    }
}

// 🔹 স্কোর ও টাইমার দেখানো
void drawScoreAndTimer() {
    setcolor(WHITE);
    char text[50];
    sprintf(text,"Score: %d",score);
    outtextxy(20,20,text);                                  // স্কোর
    int timeLeft = GAME_TIME - (time(0) - startTime);       // বাকি সময়
    if (timeLeft<0) timeLeft=0;
    sprintf(text,"Time: %02d",timeLeft);
    outtextxy(SCREEN_WIDTH-200,20,text);                   // টাইমার
}

// 🔹 গেমওভার ফাংশন
void gameOver() {
    cleardevice();   // স্ক্রিন ক্লিয়ার
    setcolor(WHITE);

    // GAME OVER লেখা
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 6);
    outtextxy(SCREEN_WIDTH/2 - 170, SCREEN_HEIGHT/2 - 120, "GAME OVER");

    // ফাইনাল স্কোর দেখানো
    char s[50];
    sprintf(s, "Final Score: %d", score);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 4);
    outtextxy(SCREEN_WIDTH/2 - 170, SCREEN_HEIGHT/2 - 40, s);

    // Restart লেখা
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 3);
    outtextxy(SCREEN_WIDTH/2 - 220, SCREEN_HEIGHT/2 + 40, "Press SPACE to Restart");

    // Swap buffers দেখানোর জন্য
    swapbuffers();

    // SPACE প্রেস করার জন্য অপেক্ষা
    while(getch() != ' ');

    // গেম রিসেট করা
    score = 0;
    startTime = time(0);
    for(int i = 0; i < MAX_GARBAGE; i++) {
        initGarbage(i);
    }
}

// 🔹 মেইন ফাংশন
int main() {
    initwindow(SCREEN_WIDTH,SCREEN_HEIGHT,"Garbage Sorting Game - Final Smooth Version");
    srand(time(NULL));
    initBins();
    for(int i=0;i<MAX_GARBAGE;i++) initGarbage(i);
    startTime=time(0);

    int activePage=0, visualPage=1;

    while(1) {
        setactivepage(activePage);
        setvisualpage(visualPage);
        cleardevice();

        drawSkyBackground();       // ব্যাকগ্রাউন্ড
        handleMouse();             // মাউস হ্যান্ডেল
        drawBins();                // বিন আঁকা
        drawScoreAndTimer();       // স্কোর ও টাইমার

        if((time(0)-startTime)>=GAME_TIME) gameOver(); // টাইমার শেষ হলে

        for(int i=0;i<MAX_GARBAGE;i++) {
            garbages[i].y += FALL_SPEED;  // আবর্জনা নিচে নামানো
            if(garbages[i].y > SCREEN_HEIGHT)
                initGarbage(i);          // নিচে গেলে নতুন করে
            checkCollision(garbages[i]);  // কোলিশন চেক
            drawGarbage(garbages[i]);     // আঁকা
        }

        delay(25);
        std::swap(activePage, visualPage); // ডাবল বাফারিং
    }

    closegraph(); // গ্রাফিক্স বন্ধ
    return 0;
}
