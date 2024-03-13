
import java.util.List;
import java.util.ArrayList;
import java.util.Map;

public class SelectionSort {
	myMap originalMap;
	myMap sortedMap;
	List<String> aux;


	public SelectionSort(myMap originalMap) {
		super();
		this.originalMap = originalMap;
		this.aux = new ArrayList<String>(this.originalMap.map.keySet());
		this.sortedMap = new myMap();
	}

	
	
	private void generateNewMap() {
		for (int i = 0; i < aux.size(); i++)
			this.sortedMap.assign(aux.get(i), this.originalMap.map.get(aux.get(i)).words);
	}
	 
	



	private void search_sort(){
		int n = aux.size();

        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
			 // Find the index of the minimum element in the remaining unsorted part of the list
            for (int j = i + 1; j < n; j++) {
                if (originalMap.map.get(((List<String>) this.aux).get(minIndex)).count > originalMap.map.get(((List<String>) this.aux).get(j)).count) {

                    minIndex = j;
                }
            }
			// Swap the minimum element with the current element
            String temp = aux.get(minIndex);
            aux.set(minIndex, aux.get(i));
            aux.set(i, temp);
        }
	}
	public void sort(){	
        
	    search_sort();
        int endTime = (int)System.nanoTime();
        
	    generateNewMap();
	}
    public void give_time_complexity(){
		int startTime = (int)System.nanoTime();		

		for(int i=0;i<10000;i++){
			List<String> temp=new ArrayList<>(this.aux);

			search_sort();

			for(int j=0;j<temp.size();j++){

				aux.set(j,temp.get(j));
			}

		}

		int endTime = (int)System.nanoTime();
        double runningTime = (endTime - startTime)/ 1_000_000.0;

        System.out.println("Running time: " + runningTime + " milliseconds");

	}

	public void calculate_run_time(){
        List<String> temp= new ArrayList<String>();

        for (String element : aux) {
            temp.add(element);
        }

        

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