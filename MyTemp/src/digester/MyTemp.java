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
		Scanner input = new Scanner(System.in);//从控制台获取用户的输入
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
	    ////不进行XML与相应的DTD的合法性验证
	    digester.setValidating(false);
	    ////如果遇到匹配“charts/chart”形式的节点，就执行一个“对象创建”操作，Class为“ChartConfig.class”的对象
	    digester.addObjectCreate("charts/chart", ChartConfig.class);
	    //addSetProperties()是告诉Digester将指定节点的属性全部映射到对象的属性，在这个例子里指的就是id属性
	    digester.addSetProperties("charts/chart");
	    //addBeanPropertySetter()是将子节点转换为对象的属性，这个方法还可以有第二个参数，当对象的属性名和子节点的名字不一样时用来指定对象的属性名
	    digester.addBeanPropertySetter("charts/chart/legendVisible"); 
	    digester.addBeanPropertySetter("charts/chart/type"); 
	    digester.addBeanPropertySetter("charts/chart/width"); 
	    digester.addBeanPropertySetter("charts/chart/description"); 
	    //addSetNext()是说在遇到匹配节点后，对当前对象的父对象执行一个方法，参数是当前参数，对这个例子来说就是执行ChartConfig.register(ChartConfig)方法
	    digester.addSetNext("charts/chart","addChart");
	    
	    MyTemp oChartConfig  = new MyTemp();
	    oChartConfig = (MyTemp)digester.parse(is);  //分析结束后，返回根元素
        Collections.sort(registry);

	    
	    //ChartConfig oChartConfig = (ChartConfig)digester.parse(new FileInputStream ("D:\\charts.xml"));
	   // if(oChartConfig.getId() == ""){
	    	//System.out.println("Success");
	   // }
	    //Collections.sort(registry);
	}

}
