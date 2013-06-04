package Java.my.XMLinput;

import java.util.ArrayList;
import java.util.List;

public class Book {
	private String        title;  
	private String        author;  
	private ArrayList<Chapter> chapters = new ArrayList<Chapter>();  //泛型的使用
	//private List<Chapter> chapters = new ArrayList<Chapter>();  //当使用List去定义的时候，是使用了借口，而Arraylist实现了List的借口
	 /** 
	* 这个方法，用来演示xml的解析时用的另一种方式 
	* @param title 
	* @param author 
	*/  
	public void setBookInfo(String title, String author) {  
	    this.title = title;  
	    this.author = author;  
	}  
	 /* (non-Javadoc)
	 * @see java.lang.Object#toString()
	 */
	@Override
	public String toString() {
		return "Book title:"+title +"Book author: "+ author;
	}
	public void addChapter(Chapter chapter) {  
	   this.chapters.add(chapter);  
	}  
	 public String getTitle() {  
	        return title;  
	 }  
	 public void setTitle(String title) {  
	       this.title = title;  
	 }  
	 public String getAuthor() {  
	      return author;  
	    }   
     public void setAuthor(String author) {  
	     this.author = author;  
	   }    
	  public List<Chapter> getChapters() {  
	        return chapters;  
	   }  
	  public void setChapters(ArrayList<Chapter> chapters) {  
	      this.chapters = chapters;  
	   } 
}
