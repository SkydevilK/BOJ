import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int note[] = new int[11];

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		String s = bf.readLine();
		StringTokenizer st = new StringTokenizer(s);
		int TestCase = Integer.parseInt(st.nextToken());
		note[1] = 1;
		note[2] = 2;
		note[3] = 4;
		for (int i = 4; i <= 10; ++i)
			note[i] = note[i - 1] + note[i - 2] + note[i - 3];
		for (int t = 0; t < TestCase; ++t) {
			s = bf.readLine();
			int n = Integer.parseInt(s);
			System.out.println(note[n]);
		}
	}
}
