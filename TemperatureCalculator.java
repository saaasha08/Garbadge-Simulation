import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;
import javax.swing.*;

public class TemperatureCalculator {

    private JFrame frmTemperatureCalculator;
    private JComboBox<String> comboBox2;
    private JTextField textField1;
    private JTextField textField2;
    private JButton convertButton;

    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            try {
                TemperatureCalculator window = new TemperatureCalculator();
                window.frmTemperatureCalculator.setVisible(true);
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }

    public TemperatureCalculator() {
        initialize();
    }

    private void initialize() {
        frmTemperatureCalculator = new JFrame();
        frmTemperatureCalculator.setBackground(Color.WHITE);
        frmTemperatureCalculator.setTitle("Temperature Calculator");
        // Optional: Remove or replace this icon with a valid local path
        // frmTemperatureCalculator.setIconImage(Toolkit.getDefaultToolkit().getImage("logo.png"));
        frmTemperatureCalculator.getContentPane().setBackground(new Color(153, 204, 153));
        frmTemperatureCalculator.setBounds(100, 100, 391, 526);
        frmTemperatureCalculator.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frmTemperatureCalculator.getContentPane().setLayout(null);

        JComboBox<String> comboBox1 = new JComboBox<>();
        comboBox1.setFont(new Font("Tahoma", Font.BOLD, 18));
        comboBox1.setBounds(11, 41, 149, 35);
        frmTemperatureCalculator.getContentPane().add(comboBox1);
        comboBox1.addItem("Celsius");
        comboBox1.addItem("Fahrenheit");
        comboBox1.addItem("Kelvin");

        comboBox2 = new JComboBox<>();
        comboBox2.setFont(new Font("Tahoma", Font.BOLD, 18));
        comboBox2.setBounds(11, 137, 149, 38);
        frmTemperatureCalculator.getContentPane().add(comboBox2);
        comboBox2.addItem("Celsius");
        comboBox2.addItem("Fahrenheit");
        comboBox2.addItem("Kelvin");

        textField1 = new JTextField();
        textField1.setFont(new Font("Tahoma", Font.BOLD, 18));
        textField1.setBounds(12, 89, 349, 35);
        frmTemperatureCalculator.getContentPane().add(textField1);
        textField1.setColumns(10);

        textField2 = new JTextField();
        textField2.setFont(new Font("Tahoma", Font.BOLD, 18));
        textField2.setColumns(10);
        textField2.setEditable(false);
        textField2.setBounds(12, 183, 349, 38);
        frmTemperatureCalculator.getContentPane().add(textField2);

        convertButton = new JButton("=");
        convertButton.setForeground(Color.WHITE);
        convertButton.setBackground(new Color(0, 102, 102));
        convertButton.setFont(new Font("Tahoma", Font.BOLD, 18));
        convertButton.addActionListener(e -> convertTemperature(comboBox1));
        convertButton.setBounds(245, 420, 116, 46);
        frmTemperatureCalculator.getContentPane().add(convertButton);

        String[] buttons = {
            "7", "8", "9",
            "4", "5", "6",
            "1", "2", "3",
            ".", "0", "="
        };

        int x = 12, y = 281;
        int btnWidth = 116, btnHeight = 46, gap = 1;

        for (int i = 0; i < 12; i++) {
            JButton btn = new JButton(buttons[i]);
            btn.setFont(new Font("Tahoma", Font.BOLD, 18));
            btn.setForeground(Color.WHITE);
            btn.setBackground(new Color(0, 102, 102));
            btn.setBounds(x, y, btnWidth, btnHeight);
            String value = buttons[i];
            btn.addActionListener(e -> {
                if (!value.equals("=")) {
                    textField1.setText(textField1.getText() + value);
                }
            });
            frmTemperatureCalculator.getContentPane().add(btn);

            x += btnWidth + gap;
            if ((i + 1) % 3 == 0) {
                x = 12;
                y += btnHeight + gap;
            }
        }

        JButton btnCE = new JButton("CE");
        btnCE.setFont(new Font("Tahoma", Font.BOLD, 18));
        btnCE.setForeground(Color.WHITE);
        btnCE.setBackground(new Color(0, 102, 102));
        btnCE.setBounds(129, 234, 116, 46);
        btnCE.addActionListener(e -> textField1.setText(""));
        frmTemperatureCalculator.getContentPane().add(btnCE);
        // Exit button (beside CE)
JButton btnExit = new JButton("Exit");
btnExit.setFont(new Font("Tahoma", Font.BOLD, 18));
btnExit.setForeground(Color.WHITE);
btnExit.setBackground(new Color(204, 0, 0));
btnExit.setBounds(12, 234, 116, 46); // Same y as CE and Del

btnExit.addActionListener(e -> System.exit(0));
frmTemperatureCalculator.getContentPane().add(btnExit);


        JButton btnDel = new JButton("Del");
        btnDel.setFont(new Font("Tahoma", Font.BOLD, 18));
        btnDel.setForeground(Color.WHITE);
        btnDel.setBackground(new Color(0, 102, 102));
        btnDel.setBounds(245, 234, 116, 46);
        btnDel.addActionListener(e -> {
            String text = textField1.getText();
            if (!text.isEmpty()) {
                textField1.setText(text.substring(0, text.length() - 1));
            }
        });
        frmTemperatureCalculator.getContentPane().add(btnDel);

        JLabel lblAuthor = new JLabel("Developed by Md. Sohanur Rahman");
        lblAuthor.setFont(new Font("Tahoma", Font.PLAIN, 16));
        lblAuthor.setBounds(11, 0, 306, 35);
        frmTemperatureCalculator.getContentPane().add(lblAuthor);
        

    }

    private void convertTemperature(JComboBox<String> comboBox1) {
        try {
            double inputTemperature = Double.parseDouble(textField1.getText());
            String fromUnit = (String) comboBox1.getSelectedItem();
            String toUnit = (String) comboBox2.getSelectedItem();
            double convertedTemperature;
            double Celsius;

            // Convert to Celsius
            switch (fromUnit) {
                case "Celsius":
                    Celsius = inputTemperature;
                    break;
                case "Fahrenheit":
                    Celsius = (inputTemperature - 32) * (5.0 / 9.0);
                    break;
                case "Kelvin":
                    Celsius = inputTemperature - 273.15;
                    break;
                default:
                    Celsius = 0;
                    break;
            }

            // Convert from Celsius to desired unit
            switch (toUnit) {
                case "Celsius":
                    convertedTemperature = Celsius;
                    break;
                case "Fahrenheit":
                    convertedTemperature = (Celsius * (9.0 / 5.0)) + 32;
                    break;
                case "Kelvin":
                    convertedTemperature = Celsius + 273.15;
                    break;
                default:
                    textField2.setText("Invalid conversion");
                    return;
            }

            textField2.setText(String.format("%.2f", convertedTemperature));
        } catch (NumberFormatException ex) {
            JOptionPane.showMessageDialog(frmTemperatureCalculator, "Please enter a valid number!");
        }
    }
}