import javax.swing.*;
import java.lang.Thread;
import java.util.Scanner;
import java.awt.Dimension;
import java.util.concurrent.*;

class Java {
	static class Loop implements Runnable {
		int n = -1;

		public Loop(int n) {
			this.n = n;
		}

		public void run() {
			var id = Thread.currentThread().getId();
			trySleep(500L);
			System.out.printf("T%d = %d\n", id, n);
			trySleep(500L);
		}

		boolean trySleep(long millis) {
			try {
				Thread.sleep(500L);
			} catch (InterruptedException e) {
				return false;
			};
			return true;
		}
	}
	
	static void shutdown(ExecutorService executor) {
		executor.shutdown();
		while (true) {
			try {
				if (executor.awaitTermination(1L, TimeUnit.SECONDS)) break;
			} catch (InterruptedException e) {};
		}
	}

	public static void main(String[] args) {
		int threads, n, i;
		ExecutorService executor;

		SwingUtilities.invokeLater(() -> {
			var frame = new JFrame("patan-java");
			frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
			frame.setMinimumSize(new Dimension(256, 144));
			var text = new JTextField("Wait for terminal");
			text.setHorizontalAlignment(JTextField.CENTER);
			frame.add(text);
			frame.pack();
			frame.setVisible(true);
		});

		threads = 2;
		var scanner = new Scanner(System.in);

		n = -1;
		executor = Executors.newFixedThreadPool(threads);
		if (args.length == 1) n = Integer.parseInt(args[0]); System.out.printf("n = %d\n", n);
		for (i = 0; i < threads; i++) executor.execute(new Loop(n));
		Java.shutdown(executor);

		n = -1;
		executor = Executors.newFixedThreadPool(threads);
		System.out.printf("n = "); System.out.flush(); n = scanner.nextInt();
		for (i = 0; i < threads; i++) executor.execute(new Loop(n));
		Java.shutdown(executor);
	}
}
