
import java.util.LinkedHashMap;
import java.util.ArrayList;

public class myMap {
	LinkedHashMap <String, info> map;
	int mapSize;
	String str;
	String [] words;

	public myMap() {
		this.map = new LinkedHashMap<String, info>();
		this.mapSize = 0;
		this.str = null;
		this.words = null;
	}
	
	public void append(String x, String word) {
		if (this.map.containsKey(x)) {
			info myinfo = this.map.get(x);
			myinfo.push(word);
		}
		else
			addNewCharacter(x, word);
	}
	
	
	private void addNewCharacter (String x, String word) {
		ArrayList<String> words = new ArrayList<String>();
		words.add(word);
		info myInfo = new info (1, words);
		this.map.put(x, myInfo);
		this.mapSize ++;
	}
	
	public void assign(String x, ArrayList<String> words) {
		addNewCharacter(x, (String) words.get(0));
		for (int i = 1; i < words.size(); i++) {
			append(x, (String) words.get(i));
		}
	}
	
	public void buildMap (String str) {
		this.str = str.replaceAll("[^a-zA-Z\\s]", "").toLowerCase();
		this.words = this.str.split(" ");
		for (int i = 0; i < this.words.length; i++) {
			for (int j = 0; j < this.words[i].length(); j++) {
				append(this.words[i].substring(j, j + 1), this.words[i]);
			}
		}
	}
	
}
