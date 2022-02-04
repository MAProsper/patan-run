import javax.swing.*;

class Main {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            var container = new JFrame("Window");
            container.add(new JTextField("Wait for console"));
            container.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            container.setVisible(true);
        });

        new Thread(() -> {
            try { Thread.sleep(5000L); }
            catch (InterruptedException ignored) {}
            System.out.println(args.length == 1 ? Integer.parseInt(args[0]) : -1);
        }).start();
    }
}