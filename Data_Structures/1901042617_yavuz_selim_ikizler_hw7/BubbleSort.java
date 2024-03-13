
import java.util.List;
import java.util.ArrayList;
import java.util.Map;

public class BubbleSort {
	myMap originalMap;
	myMap sortedMap;
	List<String> aux;


	public BubbleSort(myMap originalMap) {
		super();
		this.originalMap = originalMap;
		this.aux = new ArrayList<String>(this.originalMap.map.keySet());
		this.sortedMap = new myMap();
	}

	
	
	private void generateNewMap() {
		for (int i = 0; i < aux.size(); i++)
			this.sortedMap.assign(aux.get(i), this.originalMap.map.get(aux.get(i)).words);
	}
	 
	
	// The outer loop runs from 0 to n - 2 (inclusive) to perform (n-1) passes through the list
    // The inner loop runs from 0 to (n - i - 2) (inclusive) in order to compare adjacent elements
    // If the count of the current element is greater than the count of the next element, swap them
    // This process is repeated until the entire list is sorted in ascending order
	private void bubble_sort(){
		int n = aux.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (originalMap.map.get(((List<String>) this.aux).get(j)).count > originalMap.map.get(((List<String>) this.aux).get(j+1)).count) {
                    String temp = aux.get(j);
                    aux.set(j, aux.get(j + 1));
                    aux.set(j + 1, temp);
                }
            }
        }
	}
    public void give_time_complexity(){
		int startTime = (int)System.nanoTime();		

		for(int i=0;i<10000;i++){
			List<String> temp=new ArrayList<>(this.aux);

			bubble_sort();

			for(int j=0;j<temp.size();j++){

				aux.set(j,temp.get(j));
			}

		}

		int endTime = (int)System.nanoTime();
        double runningTime = (endTime - startTime)/ 1_000_000.0;

        System.out.println("Running time: " + runningTime + " milliseconds");

	}
	public void sort(){	
        
	    bubble_sort();

       
	    generateNewMap();
	}

	
	public void printSortedArray(){
	    for (Map.Entry<String, info> e : sortedMap.map.entrySet())
            System.out.println("Letter: " + e.getKey() + " - Count: "
                               + e.getValue().count + " - Words: " + e.getValue().words);
	}

	public void printOriginalArray(){
	    for (Map.Entry<String, info> e : originalMap.map.entrySet())
            System.out.println("Letter: " + e.getKey() + " - Count: "
                               + e.getValue().count + " - Words: " + e.getValue().words);
	}
}