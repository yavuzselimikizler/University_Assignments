
import java.util.List;
import java.util.ArrayList;
import java.util.Map;

public class QuickSort {
	myMap originalMap;
	myMap sortedMap;
	List<String> aux;


	public QuickSort(myMap originalMap) {
		super();
		this.originalMap = originalMap;
		this.aux = new ArrayList<String>(this.originalMap.map.keySet());
		this.sortedMap = new myMap();
	}

	
	
	private void generateNewMap() {
		for (int i = 0; i < aux.size(); i++)
			this.sortedMap.assign(aux.get(i), this.originalMap.map.get(aux.get(i)).words);
	}
	 
	



	private void quick_sort(int low ,int high){
        if (low < high) {
            int partitionIndex = partition(low, high);
            quick_sort( low, partitionIndex - 1);	 // Sort the left partition
            quick_sort( partitionIndex + 1, high);	// Sort the right partition
        }
	}
    private int partition(int low, int high) {
        int pivot = originalMap.map.get(((List<String>) this.aux).get(high)).count;
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (pivot > originalMap.map.get(((List<String>) this.aux).get(j)).count) {
                i++;
                String temp = aux.get(i);
                aux.set(i, aux.get(j));
                aux.set(j, temp);
            }
        }

        String temp = aux.get(i + 1);
        aux.set(i + 1, aux.get(high));
        aux.set(high, temp);

        return i + 1;	// Return the updated partition index
    }

    public void give_time_complexity(){
		int startTime = (int)System.nanoTime();		

		for(int i=0;i<10000;i++){ // repeat the process 10000 times.
			List<String> temp=new ArrayList<>(this.aux); //copy the content temprorly.

			quick_sort(0,this.originalMap.mapSize - 1);

			for(int j=0;j<temp.size();j++){ // take the content back.

				aux.set(j,temp.get(j));
			}

		}

		int endTime = (int)System.nanoTime(); // track the wasted time.
        double runningTime = (endTime - startTime)/ 1_000_000.0;

        System.out.println("Running time: " + runningTime + " milliseconds");

	}
	public void sort(){		
        
	    quick_sort(0,this.originalMap.mapSize - 1);
        
	    
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