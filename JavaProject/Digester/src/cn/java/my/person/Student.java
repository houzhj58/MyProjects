package cn.java.my.person;

public class Student {
	private int	       iStuNO;
	private String     strStuName;
	//�Ҽ���source������ֱ����������Ԫ�ص�setter��getter����
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
