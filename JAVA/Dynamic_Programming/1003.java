import java.util.Scanner;

public class Main {
	static int note_zero[] = new int[41];
	static int note_one[] = new int[41];

	static void dp() {
		for (int i = 2; i < 41; ++i) {
			note_zero[i] = note_zero[i - 2] + note_zero[i - 1];
			note_one[i] = note_one[i - 2] + note_one[i - 1];
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		note_zero[0] = 1;
		note_one[0] = 0;
		note_zero[1] = 0;
		note_one[1] = 1;
		dp();
		int TestCase = sc.nextInt();
		for (int testcase = 1; testcase <= TestCase; ++testcase) {
			int N = sc.nextInt();
			System.out.println(note_zero[N] + " " + note_one[N]);
		}
	}
}
