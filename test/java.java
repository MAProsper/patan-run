import javax.swing.*;
import java.awt.*;

class Main {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            var container = new JFrame("Window");
            container.add(new JTextField("Wait for console"));

            new Thread(() -> {
                try {
                    Thread.sleep(1L);
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }
                System.out.println(args.length == 2 ? Integer.parseInt(args[1]) : -1);
            }).start();

            container.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            container.pack();
            container.setVisible(true);
        });
    }
}