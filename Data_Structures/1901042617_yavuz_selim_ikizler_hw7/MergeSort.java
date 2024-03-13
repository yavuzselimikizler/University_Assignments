
import java.util.List;
import java.util.ArrayList;
import java.util.Map;

public class MergeSort {
	myMap originalMap;
	myMap sortedMap;
	List<String> aux;


	public MergeSort(myMap originalMap) {
		super();
		this.originalMap = originalMap;
		this.aux = new ArrayList<String>(this.originalMap.map.keySet());
		this.sortedMap = new myMap();
	}

	public void merge(int l, int m, int r){
		int n1 = m - l + 1;
	    int n2 = r - m;

	    int L[] = new int[n1];
	    String Left[] = new String[n1];
	    int R[] = new int[n2];
	    String Right[] = new String[n2];

	    for (int i = 0; i < n1; ++i) {
	       L[i] = originalMap.map.get(((List<String>) this.aux).get(l + i)).count;
	       Left[i] = this.aux.get(l + i);
	    }
	    for (int j = 0; j < n2; ++j) {
	    	R[j] = originalMap.map.get(((List<String>) this.aux).get(m + 1 + j)).count;
	    	Right[j] = this.aux.get(m + 1 + j);
	    }

	 
	    int i = 0, j = 0;
	    int k = l;
	    while (i < n1 && j < n2) {
	    	if (L[i] <= R[j]) {
	    		aux.set(k, Left[i]);
	    		i++; 	    		
	        }
	    	
	        else {
	    		aux.set(k, Right[j]);
	        	j++;
	        }
	    	
	    	k++;
	    }
	 
	    while (i < n1) {
    		aux.set(k, Left[i]);
	    	i++;
	    	k++;
	    }
	 
	    while (j < n2) {
    		aux.set(k, Right[j]);
	    	j++;
	        k++;
	    }
	}
	
	private void generateNewMap() {
		for (int i = 0; i < aux.size(); i++)
			this.sortedMap.assign(aux.get(i), this.originalMap.map.get(aux.get(i)).words);
	}
	 
	private void sortHelper (int l, int r) {
		if (l < r) {
	        int m = l + (r - l) / 2;
	        sortHelper(l, m);
	        sortHelper(m + 1, r);
	        merge(l, m, r);
		}
	    
	}
	public void sort(){	
		
	    sortHelper (0, this.originalMap.mapSize - 1);
		
	    generateNewMap();
	}


	public void give_time_complexity(){
		int startTime = (int)System.nanoTime();		

		for(int i=0;i<100;i++){
			List<String> temp=new ArrayList<>(this.aux);

			sortHelper (0, this.originalMap.mapSize - 1);

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