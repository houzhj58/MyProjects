package Java.my.XMLinput;

import java.util.ArrayList;
import java.util.List;

public class Book {
	private String        title;  
	private String        author;  
	private ArrayList<Chapter> chapters = new ArrayList<Chapter>();  //���͵�ʹ��
	//private List<Chapter> chapters = new ArrayList<Chapter>();  //��ʹ��Listȥ�����ʱ����ʹ���˽�ڣ���Arraylistʵ����List�Ľ��
	 /** 
	* ���������������ʾxml�Ľ���ʱ�õ���һ�ַ�ʽ 
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
