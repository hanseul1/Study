import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class QuickSort {

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
		
		quickSort(0, n-1);
		
		for(int i=0; i<n; i++) {
			System.out.print(list.get(i) + " ");
		}
	}
	
	public static void quickSort(int left, int right) {
		if(left < right) {
			int pivot = partition(left, right);

			quickSort(left, pivot-1);
			quickSort(pivot+1, right);
		}
	}
	
	public static int partition(int left, int right) {
		int pivot = list.get(left);
		int i = left+1;
		int j = right;
		
		while(i < j) {
			while(i <= right && list.get(i) <= pivot) i++;
			while(j > left && list.get(j) > pivot) j--;
			
			if(i < j) swap(i, j);
		}
		swap(left, j);
		
		return j;
	}
	
	public static void swap(int i, int j) {
		int temp = list.get(i);
		list.set(i, list.get(j));
		list.set(j, temp);
	}
}
