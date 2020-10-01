public class xor_operation {
	public static void main(String[] args) {
		int n = 5;
		int start = 0;

		System.out.println(xorOperation(n, start));
	}

	public static int xorOperation(int n, int start) {

		int[] nums = new int[n];

		for (int i = 0; i < nums.length; i++) {
			nums[i] = start + 2 * i;
		}

		int ans = nums[0];

		for (int j = 1; j < nums.length; j++) {
			ans = ans ^ nums[j];
		}

		return ans;

	}
}
