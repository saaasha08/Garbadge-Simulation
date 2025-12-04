//# Reflection x//
#include <graphics.h>
#include <conio.h>
#include <iostream>
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); 
    int maxx = getmaxx();
    int maxy = getmaxy();
    int midx = maxx / 2;
    int midy = maxy / 2;
    setcolor(WHITE);
    line(0, midy, maxx, midy); 
    line(midx, 0, midx, maxy); 
    int ox1 = midx + 50;
    int oy1 = midy - 100;
    int ox2 = midx + 100;
    int oy2 = midy - 50;
    int ox3 = midx + 50;
    int oy3 = midy - 50;
    drawTriangle(ox1, oy1, ox2, oy2, ox3, oy3, RED);
    int rx1 = ox1;
    int ry1 = 2 * midy - oy1;
    int rx2 = ox2;
    int ry2 = 2 * midy - oy2;
    int rx3 = ox3;
    int ry3 = 2 * midy - oy3;
    drawTriangle(rx1, ry1, rx2, ry2, rx3, ry3, GREEN);
    setcolor(WHITE);
    outtextxy(ox1 - 20, oy1 - 20, "Original Triangle");
    outtextxy(rx1 - 20, ry1 + 10, "Reflected Triangle");
    getch();
    closegraph(); 
    return 0;
}
//# Reflection y//
#include <graphics.h>
#include <conio.h>
#include <iostream>
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int maxx = getmaxx();
    int maxy = getmaxy();
    int midx = maxx / 2;
    int midy = maxy / 2;
    setcolor(WHITE);
    line(0, midy, maxx, midy);  
    line(midx, 0, midx, maxy); 
    int ox1 = midx + 50;
    int oy1 = midy - 100;
    int ox2 = midx + 100;
    int oy2 = midy - 50;
    int ox3 = midx + 50;
    int oy3 = midy - 50;
    drawTriangle(ox1, oy1, ox2, oy2, ox3, oy3, RED);
    int rx1 = 2 * midx - ox1;
    int ry1 = oy1;
    int rx2 = 2 * midx - ox2;
    int ry2 = oy2;
    int rx3 = 2 * midx - ox3;
    int ry3 = oy3;
    drawTriangle(rx1, ry1, rx2, ry2, rx3, ry3, GREEN);
    setcolor(WHITE);
    outtextxy(ox1 - 20, oy1 - 20, "Original Triangle");
    outtextxy(rx1 - 20, ry1 - 20, "Reflected Triangle");

    getch();  
    closegraph(); 
    return 0;
}
//# Rotation //
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <cmath>
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    int maxx = getmaxx();
    int maxy = getmaxy();
    int midx = maxx / 2;
    int midy = maxy / 2;
    setcolor(WHITE);
    line(0, midy, maxx, midy); 
    line(midx, 0, midx, maxy); 
    int ox1 = midx + 50;
    int oy1 = midy - 100;
    int ox2 = midx + 100;
    int oy2 = midy - 50;
    int ox3 = midx + 50;
    int oy3 = midy - 50;
    drawTriangle(ox1, oy1, ox2, oy2, ox3, oy3, RED);
    float theta = 45 * M_PI / 180.0; 

    int rx1 = midx + (int)((ox1 - midx) * cos(theta) + (oy1 - midy) * sin(theta));
    int ry1 = midy + (int)((ox1 - midx) * sin(theta) - (oy1 - midy) * cos(theta));
    int rx2 = midx + (int)((ox2 - midx) * cos(theta) + (oy2 - midy) * sin(theta));
    int ry2 = midy + (int)((ox2 - midx) * sin(theta) - (oy2 - midy) * cos(theta));
    int rx3 = midx + (int)((ox3 - midx) * cos(theta) + (oy3 - midy) * sin(theta));
    int ry3 = midy + (int)((ox3 - midx) * sin(theta) - (oy3 - midy) * cos(theta));

    drawTriangle(rx1, ry1, rx2, ry2, rx3, ry3, GREEN);

    setcolor(WHITE);
    outtextxy(ox1 - 20, oy1 - 20, "Original Triangle");
    outtextxy(rx1 - 20, ry1 - 20, "Rotated Triangle");

    getch(); 
    closegraph();  
    return 0;
}
//# Scale//
#include <graphics.h>
#include <conio.h>
#include <iostream>

void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");  

    
    int maxx = getmaxx();
    int maxy = getmaxy();
    int midx = maxx / 2;
    int midy = maxy / 2;
    setcolor(WHITE);
    line(0, midy, maxx, midy);  
    line(midx, 0, midx, maxy); 
    int ox1 = midx + 50;
    int oy1 = midy - 100;
    int ox2 = midx + 100;
    int oy2 = midy - 50;
    int ox3 = midx + 50;
    int oy3 = midy - 50;

    drawTriangle(ox1, oy1, ox2, oy2, ox3, oy3, RED);

    float Sx = 1.5; 
    float Sy = 1.5;  

    int sx1 = midx + (int)((ox1 - midx) * Sx);
    int sy1 = midy + (int)((oy1 - midy) * Sy);
    int sx2 = midx + (int)((ox2 - midx) * Sx);
    int sy2 = midy + (int)((oy2 - midy) * Sy);
    int sx3 = midx + (int)((ox3 - midx) * Sx);
    int sy3 = midy + (int)((oy3 - midy) * Sy);


    drawTriangle(sx1, sy1, sx2, sy2, sx3, sy3, GREEN);

    setcolor(WHITE);
    outtextxy(ox1 - 20, oy1 - 20, "Original Triangle");
    outtextxy(sx1 - 20, sy1 - 20, "Scaled Triangle");

    getch();  
    closegraph();  
    return 0;
}
//# translation //
#include <graphics.h>
#include <conio.h>
#include <iostream>
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); 
    int maxx = getmaxx();
    int maxy = getmaxy();
    int midx = maxx / 2;
    int midy = maxy / 2;

    setcolor(WHITE);
    line(0, midy, maxx, midy); 
    line(midx, 0, midx, maxy); 
    int ox1 = midx + 50;
    int oy1 = midy - 100;
    int ox2 = midx + 100;
    int oy2 = midy - 50;
    int ox3 = midx + 50;
    int oy3 = midy - 50;
    drawTriangle(ox1, oy1, ox2, oy2, ox3, oy3, RED);

    int dx = 150;  
    int dy = 100;  

    int tx1 = ox1 + dx;
    int ty1 = oy1 + dy;
    int tx2 = ox2 + dx;
    int ty2 = oy2 + dy;
    int tx3 = ox3 + dx;
    int ty3 = oy3 + dy;
    drawTriangle(tx1, ty1, tx2, ty2, tx3, ty3, GREEN);
    setcolor(WHITE);
    outtextxy(ox1 - 20, oy1 - 20, "Original Triangle");
    outtextxy(tx1 - 20, ty1 - 20, "Translated Triangle");

    getch();  
    closegraph();  
    return 0;
}
//# shear x//
#include <graphics.h>
#include <conio.h>
#include <iostream>
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, ""); 

    int maxx = getmaxx();
    int maxy = getmaxy();
    int midx = maxx / 2;
    int midy = maxy / 2;

    setcolor(WHITE);
    line(0, midy, maxx, midy); 
    line(midx, 0, midx, maxy);  

    int ox1 = midx + 50;
    int oy1 = midy - 100;
    int ox2 = midx + 100;
    int oy2 = midy - 50;
    int ox3 = midx + 50;
    int oy3 = midy - 50;

  
    drawTriangle(ox1, oy1, ox2, oy2, ox3, oy3, RED);
    float sh_x = 0.5;  
    int sx1 = ox1 + (int)(sh_x * (oy1 - midy));
    int sy1 = oy1;
    int sx2 = ox2 + (int)(sh_x * (oy2 - midy));
    int sy2 = oy2;
    int sx3 = ox3 + (int)(sh_x * (oy3 - midy));
    int sy3 = oy3;
    drawTriangle(sx1, sy1, sx2, sy2, sx3, sy3, GREEN);
    setcolor(WHITE);
    outtextxy(ox1 - 20, oy1 - 20, "Original Triangle");
    outtextxy(sx1 - 20, sy1 - 20, "Sheared Triangle");

    getch();  
    closegraph();  
    return 0;
}
//# Shear y//
#include <graphics.h>
#include <conio.h>
#include <iostream>
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color) {
    setcolor(color);
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}
int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");  

    int maxx = getmaxx();
    int maxy = getmaxy();
    int midx = maxx / 2;
    int midy = maxy / 2;
    setcolor(WHITE);
    line(0, midy, maxx, midy);  
    line(midx, 0, midx, maxy);  

    int ox1 = midx + 50;
    int oy1 = midy - 100;
    int ox2 = midx + 100;
    int oy2 = midy - 50;
    int ox3 = midx + 50;
    int oy3 = midy - 50;
    drawTriangle(ox1, oy1, ox2, oy2, ox3, oy3, RED);
    float sh_y = 0.5;
    int sx1 = ox1;
    int sy1 = oy1 + (int)(sh_y * (ox1 - midx));
    int sx2 = ox2;
    int sy2 = oy2 + (int)(sh_y * (ox2 - midx));
    int sx3 = ox3;
    int sy3 = oy3 + (int)(sh_y * (ox3 - midx));
    drawTriangle(sx1, sy1, sx2, sy2, sx3, sy3, GREEN);
    setcolor(WHITE);
    outtextxy(ox1 - 20, oy1 - 20, "Original Triangle");
    outtextxy(sx1 - 20, sy1 + 10, "Sheared Triangle");
    getch(); 
    closegraph(); 
    return 0;
}
ঠিক আছে, আমি সবগুলো ব্যাখ্যা **বাংলায়** লিখে দিচ্ছি, প্রতিটি লাইনের কাজ এবং সূত্রসহ।

---

## 1️⃣ X-অক্ষের প্রতিফলন (Reflection X)

```c
int rx1 = ox1;                // X মান অপরিবর্তিত
int ry1 = 2 * midy - oy1;     // Y মান প্রতিফলিত: Ry = 2*মধ্যবিন্দুY - Oy
int rx2 = ox2;                
int ry2 = 2 * midy - oy2;     
int rx3 = ox3;                
int ry3 = 2 * midy - oy3;     
```

**সূত্র:**
[
x' = x, \quad y' = 2*midY - y
]

**ব্যাখ্যা:** ত্রিভুজের প্রতিটি বিন্দুর Y মানকে মধ্যরেখা (X-অক্ষ) দিয়ে প্রতিফলিত করা হয়।

---

## 2️⃣ Y-অক্ষের প্রতিফলন (Reflection Y)

```c
int rx1 = 2 * midx - ox1;     // X মান প্রতিফলিত: Rx = 2*মধ্যবিন্দুX - X
int ry1 = oy1;                // Y মান অপরিবর্তিত
int rx2 = 2 * midx - ox2;
int ry2 = oy2;
int rx3 = 2 * midx - ox3;
int ry3 = oy3;
```

**সূত্র:**
[
x' = 2*midX - x, \quad y' = y
]

**ব্যাখ্যা:** X মানকে মধ্যরেখা (Y-অক্ষ) দিয়ে প্রতিফলিত করা হয়, Y অপরিবর্তিত থাকে।

---

## 3️⃣ ঘূর্ণন (Rotation)

```c
float theta = 45 * M_PI / 180.0; // 45° কে রেডিয়ানে রূপান্তর
int rx1 = midx + (int)((ox1 - midx)*cos(theta) + (oy1 - midy)*sin(theta));
int ry1 = midy + (int)((ox1 - midx)*sin(theta) - (oy1 - midy)*cos(theta));
int rx2 = midx + (int)((ox2 - midx)*cos(theta) + (oy2 - midy)*sin(theta));
int ry2 = midy + (int)((ox2 - midx)*sin(theta) - (oy2 - midy)*cos(theta));
int rx3 = midx + (int)((ox3 - midx)*cos(theta) + (oy3 - midy)*sin(theta));
int ry3 = midy + (int)((ox3 - midx)*sin(theta) - (oy3 - midy)*cos(theta));
```

**সূত্র:**
[
x' = cx + (x - cx)\cosθ + (y - cy)\sinθ
]
[
y' = cy + (x - cx)\sinθ - (y - cy)\cosθ
]

**ব্যাখ্যা:** ত্রিভুজকে কেন্দ্রবিন্দু (center) ঘুরিয়ে নির্দিষ্ট ডিগ্রিতে ঘূর্ণন করা হয়।

---

## 4️⃣ আকার পরিবর্তন (Scaling)

```c
float Sx = 1.5, Sy = 1.5;     // X এবং Y এর স্কেলিং ফ্যাক্টর
int sx1 = midx + (int)((ox1 - midx) * Sx);
int sy1 = midy + (int)((oy1 - midy) * Sy);
int sx2 = midx + (int)((ox2 - midx) * Sx);
int sy2 = midy + (int)((oy2 - midy) * Sy);
int sx3 = midx + (int)((ox3 - midx) * Sx);
int sy3 = midy + (int)((oy3 - midy) * Sy);
```

**সূত্র:**
[
x' = cx + (x - cx)*Sx, \quad y' = cy + (y - cy)*Sy
]

**ব্যাখ্যা:** ত্রিভুজকে কেন্দ্রবিন্দু ধরে বড় বা ছোট করা হয়।

---

## 5️⃣ স্থানান্তর (Translation)

```c
int dx = 150, dy = 100;        // X এবং Y দিকের স্থানান্তর
int tx1 = ox1 + dx;
int ty1 = oy1 + dy;
int tx2 = ox2 + dx;
int ty2 = oy2 + dy;
int tx3 = ox3 + dx;
int ty3 = oy3 + dy;
```

**সূত্র:**
[
x' = x + dx, \quad y' = y + dy
]

**ব্যাখ্যা:** ত্রিভুজকে নির্দিষ্ট দূরত্বে সরানো হয়।

---

## 6️⃣ X-অক্ষ বরাবর সিয়ার (Shear X)

```c
float sh_x = 0.5;               // X-অক্ষের সিয়ার ফ্যাক্টর
int sx1 = ox1 + (int)(sh_x*(oy1 - midy));
int sy1 = oy1;
int sx2 = ox2 + (int)(sh_x*(oy2 - midy));
int sy2 = oy2;
int sx3 = ox3 + (int)(sh_x*(oy3 - midy));
int sy3 = oy3;
```

**সূত্র:**
[
x' = x + sh_x*(y - cy), \quad y' = y
]

**ব্যাখ্যা:** Y মানের সাথে X মানকে ঘষে (shift) ত্রিভুজকে ঢালু করা হয়।

---

## 7️⃣ Y-অক্ষ বরাবর সিয়ার (Shear Y)

```c
float sh_y = 0.5;               // Y-অক্ষের সিয়ার ফ্যাক্টর
int sx1 = ox1;
int sy1 = oy1 + (int)(sh_y*(ox1 - midx));
int sx2 = ox2;
int sy2 = oy2 + (int)(sh_y*(ox2 - midx));
int sx3 = ox3;
int sy3 = oy3 + (int)(sh_y*(ox3 - midx));
```

**সূত্র:**
[
x' = x, \quad y' = y + sh_y*(x - cx)
]

**ব্যাখ্যা:** X মানের সাথে Y মানকে ঘষে (shift) ত্রিভুজকে ঢালু করা হয়।

