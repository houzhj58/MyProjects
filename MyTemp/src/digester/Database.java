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
	 * ���ݿ������
	 * 
	 * @param mDriver
	 *            ����������������
	 * @param mURL
	 *            ���ݿ�ĵ�ַ
	 * @param mUsername
	 *            ���ݿ���û���
	 * @param mPassword
	 *            ���ݿ������
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
	 * ִ�в����ؽ������SQL���
	 * 
	 * @param mSQL
	 *            SQL���
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
	 * ִ�з��ؽ������SQL���
	 * 
	 * @param mSQL
	 *            ִ�е�SQL���
	 * @return ���ؽ����
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
	 * �ر����ݿ�����
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
