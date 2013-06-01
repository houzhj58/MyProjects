package digester;

import org.apache.commons.digester.*;
import org.xml.sax.SAXException;
import java.io.*;
import java.net.MalformedURLException;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Collections;
import java.util.ArrayList; 
import java.util.List;
import java.util.Scanner;
public class MyTemp {

	List<ChartConfig> registry = new ArrayList<ChartConfig>();
    public void addChart(ChartConfig obj)
    {
        registry.add(obj);
    }
    public java.util.List<ChartConfig> getRegistry()
    {
        return registry;
    }
	
	public static void main(String[] args) throws MalformedURLException, IOException, SAXException {
		 		//MyTemp oMyTemp = new MyTemp();
		 		//oMyTemp.deregister();
		 		//System.exit(0);
		Scanner input = new Scanner(System.in);//�ӿ���̨��ȡ�û�������
		System.out.print("Please input your DBUsername:");
		String strUsername = input.next();
		System.out.print("Please input your DBPassword:");
		String strPassword = input.next();
			Database oDatabase = new Database();
			String sClassDriver = "org.postgresql.Driver";
			String m_sURL = "jdbc:postgresql://localhost/postgres";
			String sUserName = "postgres";
			String sPassword = "qaz--123";
			oDatabase.DBConnection(sClassDriver, m_sURL, sUserName, sPassword);
			String strSQL = "select * from pg_tables";
			ResultSet oResultSet = oDatabase.DBexecuteQuery(strSQL);
			try {
				while(oResultSet.next()){
					String strSchema = oResultSet.getString("schemaname");
					String strTablename = oResultSet.getString("tablename");
				}
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		 } 
	
	public void deregister() throws IOException,SAXException{
	    InputStream is = new FileInputStream("D:\\charts.xml");
	    Digester digester = new Digester();
	    //
	    digester.push(new MyTemp());
	    ////������XML����Ӧ��DTD�ĺϷ�����֤
	    digester.setValidating(false);
	    ////�������ƥ�䡰charts/chart����ʽ�Ľڵ㣬��ִ��һ�������󴴽���������ClassΪ��ChartConfig.class���Ķ���
	    digester.addObjectCreate("charts/chart", ChartConfig.class);
	    //addSetProperties()�Ǹ���Digester��ָ���ڵ������ȫ��ӳ�䵽��������ԣ������������ָ�ľ���id����
	    digester.addSetProperties("charts/chart");
	    //addBeanPropertySetter()�ǽ��ӽڵ�ת��Ϊ��������ԣ���������������еڶ�������������������������ӽڵ�����ֲ�һ��ʱ����ָ�������������
	    digester.addBeanPropertySetter("charts/chart/legendVisible"); 
	    digester.addBeanPropertySetter("charts/chart/type"); 
	    digester.addBeanPropertySetter("charts/chart/width"); 
	    digester.addBeanPropertySetter("charts/chart/description"); 
	    //addSetNext()��˵������ƥ��ڵ�󣬶Ե�ǰ����ĸ�����ִ��һ�������������ǵ�ǰ�����������������˵����ִ��ChartConfig.register(ChartConfig)����
	    digester.addSetNext("charts/chart","addChart");
	    
	    MyTemp oChartConfig  = new MyTemp();
	    oChartConfig = (MyTemp)digester.parse(is);  //���������󣬷��ظ�Ԫ��
        Collections.sort(registry);

	    
	    //ChartConfig oChartConfig = (ChartConfig)digester.parse(new FileInputStream ("D:\\charts.xml"));
	   // if(oChartConfig.getId() == ""){
	    	//System.out.println("Success");
	   // }
	    //Collections.sort(registry);
	}

}
