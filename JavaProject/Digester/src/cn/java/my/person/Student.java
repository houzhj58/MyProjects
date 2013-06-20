package cn.java.my.person;

public class Student {
	private int	       iStuNO;
	private String     strStuName;
	//右键点source，可以直接生成类内元素的setter和getter函数
	public void setStrStuName(String strStuName) {
		this.strStuName = strStuName;
	}
	public String getStrStuName() {
		return strStuName;
	}
	public void setIStuNO(int iStuNO) {
		this.iStuNO = iStuNO;
	}
	public int getIStuNO() {
		return iStuNO;
	}
	public Student(int stuNO, String strStuName) {
		super();
		iStuNO = stuNO;
		this.strStuName = strStuName;
	}
	
}
