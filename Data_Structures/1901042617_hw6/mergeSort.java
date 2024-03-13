import java.util.List;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Set;
import java.util.Map;
import java.util.LinkedHashMap;
import java.util.regex.*;

public class mergeSort{

    private myMap originalMap;
    private myMap sortedMap;
    ArrayList<String> aux;

    mergeSort(myMap map1){
        aux=new ArrayList<String>();
        originalMap=map1;
        sortedMap=new myMap();
        
        for (Map.Entry<String, info> entry : originalMap.get().entrySet()) { // iterate original map one by one and add the key values to aux list respectively.
            aux.add(entry.getKey());
            
            
        }

        mergeSort(aux); // call mergesort method with aux list.
        while(!aux.isEmpty()){//until aux list is empty.
            String key_value=aux.remove(0); // get the first item of list every time
            info temp= originalMap.get().get(key_value); //get the corresponding info object regarding the key value.
            info new_info= new info(temp.get_words2());
            sortedMap.put(key_value,new_info); // call the put method with parametre key and info.
        }
        



    }
    //return min.
    private int min(int a, int b) {
        if (a < b) {
            return a;
        } else {
            return b;
        }
    }

    public  void mergeSort(ArrayList<String> arr) {
        int n = arr.size();
    
        // Merge subarrays of size 1, then size 2, then size 4, etc.
        for (int size = 1; size <= n-1; size = 2*size) {
    
            // Merge subarrays of size "size"
            for (int leftStart = 0; leftStart < n-1; leftStart += 2*size) {
    
                int mid = min(leftStart + size - 1, n-1);
                int rightEnd = min(leftStart + 2*size - 1, n-1);
    
                // Merge the two subarrays
                merge(arr, leftStart, mid, rightEnd);
            }
        }
    }
    
    public void merge(ArrayList<String> arr, int left, int mid, int right) {
        int leftSize = mid - left + 1;
        int rightSize = right - mid;
    
        // Create temp ArrayLists to hold the left and right subarrays
        ArrayList<String> leftArr = new ArrayList<String>();
        ArrayList<String> rightArr = new ArrayList<String>();
    
        // Copy data from arr[] to the left and right temp ArrayLists
        for (int i = 0; i < leftSize; i++) {
            leftArr.add(arr.get(left + i));
        }
        for (int j = 0; j < rightSize; j++) {
            rightArr.add(arr.get(mid + 1 + j));
        }
    
        // Merge the two temp ArrayLists into arr[]
        int i = 0, j = 0, k = left;
        while (i < leftSize && j < rightSize) {
            if (originalMap.get().get(leftArr.get(i)).get_count() <= originalMap.get().get(rightArr.get(j)).get_count()) {
                arr.set(k, leftArr.get(i));
                i++;
            }
            else {
                arr.set(k, rightArr.get(j));
                j++;
            }
            k++;
        }
    
        // Copy any remaining elements of leftArr[] and rightArr[] into arr[]
        while (i < leftSize) {
            arr.set(k, leftArr.get(i));
            i++;
            k++;
        }
        while (j < rightSize) {
            arr.set(k, rightArr.get(j));
            j++;
            k++;
        }
    }

    public void print_maps(){ // call the print methods.
        System.out.println("\n Original\n");
        originalMap.to_String();
        System.out.println("\nSorted\n");
        sortedMap.to_String();
    }






}