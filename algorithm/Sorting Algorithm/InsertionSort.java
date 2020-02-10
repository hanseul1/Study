import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class InsertionSort {

	static int n;
	static List<Integer> list = new ArrayList<>();
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		n = s.nextInt();
		
		for(int i=0; i<n; i++) {
			list.add(s.nextInt());
		}
		
		sort();
		
		for(int i=0; i<n; i++) {
			System.out.print(list.get(i) + " ");
		}
	}
	
	public static void sort() {
		for(int i = 1; i < n; i++) {
			for(int j = i-1; j >= 0; j--) {
				if(list.get(j) > list.get(j+1))
					swap(j, j+1);
			}
		}
	}
	
	public static void swap(int i, int j) {
		int temp = list.get(i);
		list.set(i, list.get(j));
		list.set(j, temp);
	}
}
