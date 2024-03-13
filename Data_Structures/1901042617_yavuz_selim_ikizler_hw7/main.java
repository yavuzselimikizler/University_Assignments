


public class main {

	public static void main(String[] args) { 
		// String str = "'Hush, hush!' whispered the rushing wind.";
		String str = "'Hush, hush!' whispered the rushing wind.";
		
		myMap newMapObj = new myMap();
		newMapObj.buildMap(str);
		System.out.println("Original String:\t" + str);
		System.out.println("Preprocessed String:\t" + newMapObj.str);
		MergeSort ms = new MergeSort(newMapObj);
		SelectionSort sl = new SelectionSort(newMapObj);
		InsertionSort is = new InsertionSort(newMapObj);
		BubbleSort bs = new BubbleSort(newMapObj);
		QuickSort qs = new QuickSort(newMapObj);
		System.out.println(".................................................");
		System.out.println("\n....................merge_sort................\n");
		System.out.println(".................................................");
		String str_best="a bb ccc dddd eeeee ffffff ";
		String str_worst= "a dddd bb eeeee ccc ffffff ";
		String str_average= "eeeee ccc ffffff a dddd bb";

		
		myMap map1= new myMap();
		myMap map2= new myMap();
		myMap map3= new myMap();
		
		map1.buildMap(str_best);
		map2.buildMap(str_worst);
		map3.buildMap(str_average);

		System.out.println("Original String:\t" + str_best);
		System.out.println("Preprocessed String:\t" + map1.str);

		System.out.println("Original String:\t" + str_worst);
		System.out.println("Preprocessed String:\t" + map2.str);
		
		MergeSort ms_best= new MergeSort(map1);
		MergeSort ms_worst= new MergeSort(map2);
		MergeSort ms_average= new MergeSort(map3);

		System.out.println("\n\nThe original (unsorted) map:");
		ms_best.printOriginalArray();
		System.out.println("the best running time");
		ms_best.give_time_complexity();
		System.out.println("the average running time");
		ms_average.give_time_complexity();
		System.out.println("the worst running time");
		ms_worst.give_time_complexity();

		ms_average.sort();
		ms_worst.sort();
		ms_best.sort();
		System.out.println("\n\nThe sorted map:");
		ms_best.printSortedArray();

		System.out.println(".................................................");
		System.out.println("\n....................selection_sort................\n");
		System.out.println(".................................................");

		String str_best2="a bb ccc dddd eeeee ffffff ";
		String str_worst2= "ffffff eeeee dddd ccc bb a";
		String str_average2= "eeeee ccc ffffff a dddd bb";

		
		myMap map1_2= new myMap();
		myMap map2_2= new myMap();
		myMap map3_2= new myMap();
		
		map1_2.buildMap(str_best2);
		map2_2.buildMap(str_worst2);
		map3_2.buildMap(str_average2);

		System.out.println("Original String:\t" + str_best);
		System.out.println("Preprocessed String:\t" + map1_2.str);

		System.out.println("Original String:\t" + str_worst);
		System.out.println("Preprocessed String:\t" + map2_2.str);
		
		MergeSort ss_best= new MergeSort(map1_2);
		MergeSort ss_worst= new MergeSort(map2_2);
		MergeSort ss_average= new MergeSort(map3_2);

		System.out.println("\n\nThe original (unsorted) map:");
		ss_best.printOriginalArray();
		System.out.println("the best running time");
		ss_best.give_time_complexity();
		System.out.println("the average running time");
		ss_average.give_time_complexity();
		System.out.println("the worst running time");
		ss_worst.give_time_complexity();
		ss_average.sort();
		ss_worst.sort();
		ss_best.sort();
		System.out.println("\n\nThe sorted map:");
		ss_best.printSortedArray();

		System.out.println(".................................................");
		System.out.println("\n....................insertion_sort................\n");
		System.out.println(".................................................");

		String str_best3="a bb ccc dddd eeeee ffffff ";
		String str_worst3= "ffffff eeeee dddd ccc bb a";
		String str_average3= "eeeee ccc ffffff a dddd bb";

		
		myMap map1_3= new myMap();
		myMap map2_3= new myMap();
		myMap map3_3= new myMap();
		
		map1_3.buildMap(str_best3);
		map2_3.buildMap(str_worst3);
		map3_3.buildMap(str_average3);

		System.out.println("Original String:\t" + str_best);
		System.out.println("Preprocessed String:\t" + map1_3.str);

		System.out.println("Original String:\t" + str_worst);
		System.out.println("Preprocessed String:\t" + map2_3.str);
		
		MergeSort is_best= new MergeSort(map1_3);
		MergeSort is_worst= new MergeSort(map2_3);
		MergeSort is_average= new MergeSort(map3_3);

		System.out.println("\n\nThe original (unsorted) map:");
		is_best.printOriginalArray();
		System.out.println("the best running time");
		is_best.give_time_complexity();
		System.out.println("the average running time");
		is_average.give_time_complexity();
		System.out.println("the worst running time");
		is_worst.give_time_complexity();
		is_average.sort();
		is_worst.sort();
		is_best.sort();

		System.out.println(".................................................");
		System.out.println("\n....................buble_sort................\n");
		System.out.println(".................................................");

		String str_best4="a bb ccc dddd eeeee ffffff ";
		String str_worst4= "ffffff eeeee dddd ccc bb a";
		String str_average4= "eeeee ccc ffffff a dddd bb";

		
		myMap map1_4= new myMap();
		myMap map2_4= new myMap();
		myMap map3_4= new myMap();
		
		map1_4.buildMap(str_best4);
		map2_4.buildMap(str_worst4);
		map3_4.buildMap(str_average4);

		System.out.println("Original String:\t" + str_best);
		System.out.println("Preprocessed String:\t" + map1_4.str);

		System.out.println("Original String:\t" + str_worst);
		System.out.println("Preprocessed String:\t" + map2_4.str);
		
		MergeSort bs_best= new MergeSort(map1_4);
		MergeSort bs_worst= new MergeSort(map2_4);
		MergeSort bs_average= new MergeSort(map3_4);

		System.out.println("\n\nThe original (unsorted) map:");
		bs_best.printOriginalArray();
		System.out.println("the best running time");
		bs_best.give_time_complexity();
		System.out.println("the average running time");
		bs_average.give_time_complexity();
		System.out.println("the worst running time");
		bs_worst.give_time_complexity();
		bs_average.sort();
		bs_worst.sort();
		bs_best.sort();




		System.out.println("\n\nThe sorted map:");
		is_best.printSortedArray();

		System.out.println(".................................................");
		System.out.println("\n....................quick_sort................\n");
		System.out.println(".................................................");

		String str_best5="ccc bb a ffffff eeeee dddd ";
		String str_worst5= "a bb ccc dddd eeeee ffffff";
		String str_average5= "eeeee ccc ffffff a dddd bb";

		
		myMap map1_5= new myMap();
		myMap map2_5= new myMap();
		myMap map3_5= new myMap();
		
		map1_5.buildMap(str_best5);
		map2_5.buildMap(str_worst5);
		map3_5.buildMap(str_average5);

		System.out.println("Original String:\t" + str_best);
		System.out.println("Preprocessed String:\t" + map1_5.str);

		System.out.println("Original String:\t" + str_worst);
		System.out.println("Preprocessed String:\t" + map2_4.str);
		
		MergeSort qs_best= new MergeSort(map1_5);
		MergeSort qs_worst= new MergeSort(map2_5);
		MergeSort qs_average= new MergeSort(map3_5);

		System.out.println("\n\nThe original (unsorted) map:");
		qs_best.printOriginalArray();
		System.out.println("the best running time");
		qs_best.give_time_complexity();
		System.out.println("the average running time");
		qs_average.give_time_complexity();
		System.out.println("the worst running time");
		qs_worst.give_time_complexity();
		qs_average.sort();
		qs_worst.sort();
		qs_best.sort();




		System.out.println("\n\nThe sorted map:");
		qs_best.printSortedArray();


		System.out.println("\n\nThe original (unsorted) map:");
		ms.printOriginalArray();

		System.out.println("\n\nThe sorted map merge sort:");
		ms.sort();
		ms.printSortedArray();
		System.out.println("\n\nThe sorted map selection sort:");
		sl.sort();
		sl.printSortedArray();

		System.out.println("\n\nThe sorted map insertion sort:");
		is.sort();
		is.printSortedArray();

		System.out.println("\n\nThe sorted map bubble sort:");
		bs.sort();
		bs.printSortedArray();

		System.out.println("\n\nThe sorted map quick sort:");
		qs.sort();
		qs.printSortedArray();
	}
}