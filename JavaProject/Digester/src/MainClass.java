import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.text.MessageFormat;
import java.text.NumberFormat;
import java.util.ArrayList;

import org.apache.commons.digester.*;
import org.xml.sax.SAXException;
import Java.my.XMLinput.*;


public class MainClass {

	/**
	 * @param args
	 * @throws SAXException 
	 * @throws IOException 
	 * @throws FileNotFoundException 
	 * @throws SAXException 
	 * @throws IOException 
	 */
	public static void main(String[] args) throws FileNotFoundException, IOException, SAXException{
		MainClass mainclass = new MainClass();
		Library library = mainclass.DigesterXML(args[0]);
		System.out.println(" ͼ���: " + library.getName());
		
		//for each����ʹ��   �����һ��objectʱ����object����ʵ����toString������
		for(Book book:library.getBookList()){
			System.out.println(book);
		}
		//MessageFormat��ʹ��
		String SQL = MessageFormat.format("select * from Mytable where username = {0}", "houzhijian");
		System.out.println(SQL);
		double dtemp = Math.random();
		String stemp = NumberFormat.getPercentInstance().format(dtemp);//���õ�ǰϵͳ���õİٷֱȵ������ʽ
		System.out.println(stemp);
		System.exit(0);
	}
	public Library DigesterXML(String XmlPath) throws FileNotFoundException, IOException, SAXException{
		Digester digester = new Digester();
		//ָ������Ҫ��DTD��֤XML�ĵ��ĺϷ��ԡ���������Ϊ����û��ΪXML�ĵ�����DTD 
		digester.setValidating(false);
		// ��library��ǩ��ʼ����,���½�һ��Library������Ϊ������  
		digester.addObjectCreate("library", Library.class);  
		// ����library��ǩ����ֵ���ö��������,һ�ο������ö������  
		digester.addSetProperties("library");  
		// Ҳ����������ķ�����ָ��propertyName  
		// digester.addSetProperties("library", "name", "name");  
		// -----��1��Ԫ�ؿ�ʼ  
		digester.addObjectCreate("library/book", Book.class);  
		//digester.addSetProperties("library/book");  
		// ��������������������  
		digester.addCallMethod("library/book", "setBookInfo", 2);  
		digester.addCallParam("library/book", 0, "title");  
		digester.addCallParam("library/book", 1, "author");  
		/** 
		* addCallParam(String rule, int  paraIndex,String attributeName) 
		* �÷�����addCallMethod���ʹ�� 
		* int paraIndex:������Ҫ���ķ����β����,�� 0 ��ʼ,������addCallMethodָ�� 
		* String attributeName:ָ����ǩ�������� 
		*/  
		// -----��2��Ԫ�ؿ�ʼ  
		digester.addObjectCreate("library/book/chapter", Chapter.class);  
		/** addBeanPropertySetter()�ǽ��ӽڵ�ת��Ϊ��������ԣ���������������еڶ�������������������������ӽڵ�����ֲ�һ��ʱ����ָ������������� 
		�÷��������ü�ʹ�÷���������addSetProperties,ֻ����������String rule������ָ����ǩ��ֵ(�����Ǳ�ǩ������)�����ö����setter*/  
		digester.addBeanPropertySetter("library/book/chapter/no");  
		// digester.addBeanPropertySetter("library/book/chapter/no", "no");  
		/** addCallMethod(String rule,String methodName, int  paraNumber) ���� 
	    * ͬ�������ö��������,���Ƿ�ʽ�������,����Ҫ�������setter 
		* ��paraNumber = 0ʱ,���Ե���ʹ��(����Ϊ��ǩ��ֵ������),��Ȼ��Ҫ���addCallParam���� 
		*/  
		// digester.addBeanPropertySetter("library/book/chapter/caption");  
		// ����ķ�������������������һ�䣬������һ����   
		digester.addCallMethod("library/book/chapter/caption", "setCaption", 0);  
		 // addSetNext()��˵���ٴ�����ƥ��ڵ�� ���õ�ǰ����(Chapter��Ķ���)�ĸ�����(Book��Ķ���)�ķ��������������ǵ�ǰ��Ԫ�صĶ���  
		digester.addSetNext("library/book/chapter", "addChapter");  
		// -----��2��Ԫ�ؽ���   
		digester.addSetNext("library/book", "addBook");  
		// -----��1��Ԫ�ؽ���  
		return (Library) digester.parse(new FileInputStream(XmlPath));
		//Library library = (Library) digester.parse(MainClass.class.getResourceAsStream("D:\\books.xml"));
	}

}
