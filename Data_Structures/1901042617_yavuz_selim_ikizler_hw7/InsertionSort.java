
import java.util.List;
import java.util.ArrayList;
import java.util.Map;

public class InsertionSort {
	myMap originalMap;
	myMap sortedMap;
	List<String> aux;


	public InsertionSort(myMap originalMap) {
		super();
		this.originalMap = originalMap;
		this.aux = new ArrayList<String>(this.originalMap.map.keySet());
		this.sortedMap = new myMap();
	}

	
	
	private void generateNewMap() {
		for (int i = 0; i < aux.size(); i++)
			this.sortedMap.assign(aux.get(i), this.originalMap.map.get(aux.get(i)).words);
	}
	 
	



	private void insertion_sort(){
		
        int n = aux.size();

        for (int i = 1; i < n; i++) {
            int value = originalMap.map.get(((List<String>) this.aux).get(i)).count;
            int j = i - 1;
            String key = aux.get(i);
			 // Compare the value with the elements to its left and shift them to the right if they are greater
            while ( j>=0 && value < originalMap.map.get(((List<String>) this.aux).get(j)).count) {
                aux.set(j + 1, aux.get(j));
                j--;
            }
			// Place the value at the correct sorted position in the list
            aux.set(j + 1, key);
        }
	}
	public void sort(){		
        
	    insertion_sort();

        
	    generateNewMap();
	}

    public void give_time_complexity(){
		int startTime = (int)System.nanoTime();		

		for(int i=0;i<10000;i++){
			List<String> temp=new ArrayList<>(this.aux);

			insertion_sort();

			for(int j=0;j<temp.size();j++){

				aux.set(j,temp.get(j));
			}

		}

		int endTime = (int)System.nanoTime();
        double runningTime = (endTime - startTime)/ 1_000_000.0;

        System.out.println("Running time: " + runningTime + " milliseconds");

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