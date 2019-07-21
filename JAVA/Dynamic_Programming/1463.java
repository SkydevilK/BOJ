import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int min = 0;
		int[] note = new int[N + 1];
		note[1] = 0;
		if (N > 1)
			note[2] = 1;
		if (N > 2)
			note[3] = 1;
		for (int i = 4; i <= N; ++i) {
			min = note[i - 1] + 1;
			if (i % 2 == 0)
				min = min < note[i / 2] + 1 ? min : note[i / 2] + 1;
			if (i % 3 == 0)
				min = min < note[i / 3] + 1 ? min : note[i / 3] + 1;
			note[i] = min;
		}
		System.out.println(note[N]);
	}
}
