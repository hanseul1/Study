import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class MergeSort {

	static int n;
	static List<Integer> list = new ArrayList<>();
	static int[] result;
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		n = s.nextInt();
		result = new int[n];
		
		for(int i=0; i<n; i++) {
			list.add(s.nextInt());
		}
		
		mergeSort(0, n-1);
		
		for(int i=0; i<n; i++) {
			System.out.print(list.get(i) + " ");
		}
	}
	
	public static void mergeSort(int left, int right) {
		int mid = (left + right) / 2;
		
		if(left < right) {
			mergeSort(left, mid);
			mergeSort(mid+1, right);
			merge(left, mid+1, right);
		}
	}
	
	public static void merge(int first, int second, int end) {
		int i = first;
		int j = second;
		int k = first;
		
		while(i < second && j <= end) {
			if(list.get(i) < list.get(j)) result[k++] = list.get(i++);
			else result[k++] = list.get(j++);
		}
		
		while(i < second) result[k++] = list.get(i++);
		while(j <= end) result[k++] = list.get(j++);
		
		for(int a = first; a <= end; a++) {
			list.set(a, result[a]);
		}
	}
}
