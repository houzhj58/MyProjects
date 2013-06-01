package digester;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class Database {
	Connection m_oConnection = null;
	Statement m_oStatement = null;

	/**
	 * 数据库的连接
	 * 
	 * @param mDriver
	 *            加载驱动器的名称
	 * @param mURL
	 *            数据库的地址
	 * @param mUsername
	 *            数据库的用户名
	 * @param mPassword
	 *            数据库的密码
	 */
	public void DBConnection(String mDriver, String mURL, String mUsername,
			String mPassword) {
		try {
			Class.forName(mDriver);
			m_oConnection = DriverManager.getConnection(mURL, mUsername,
					mPassword);
			m_oStatement = m_oConnection.createStatement();
		} catch (ClassNotFoundException ex) {
			ex.printStackTrace();
		} catch (SQLException ex) {
			ex.printStackTrace();
		}
	}

	/**
	 * 执行不返回结果集的SQL语句
	 * 
	 * @param mSQL
	 *            SQL语句
	 */
	public void DBexecuteUpdate(String mSQL) {
		if (m_oConnection != null && m_oStatement != null) {
			try {
				m_oStatement.executeUpdate(mSQL);
			} catch (SQLException ex) {
				ex.printStackTrace();
			}
		} else {
			// error log output
			return;
		}
	}

	/**
	 * 执行返回结果集的SQL语句
	 * 
	 * @param mSQL
	 *            执行的SQL语句
	 * @return 返回结果集
	 */
	public ResultSet DBexecuteQuery(String mSQL) {
		if (m_oConnection != null && m_oStatement != null) {
			try {
				return m_oStatement.executeQuery(mSQL);
			} catch (SQLException ex) {
				ex.printStackTrace();
			}
		}
		// error log output
		return null;
	}

	/**
	 * 关闭数据库连接
	 * 
	 * @throws SQLException
	 */
	public void DBclose() throws SQLException {
		if (m_oConnection != null) {
			m_oConnection.close();
		}
		if (m_oStatement != null) {
			m_oStatement.close();
		}
	}
}
