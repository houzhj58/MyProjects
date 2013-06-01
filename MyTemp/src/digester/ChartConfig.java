package digester;

public class ChartConfig implements Comparable {
	private String id;
	private boolean legendVisible;
	private String type;
	private int width;
	private String description;

	public String getDescription() {
		return description;
	}

	public void setDescription(String description) {
		this.description = description;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public boolean isLegendVisible() {
		return legendVisible;
	}

	public void setLegendVisible(boolean legendVisible) {
		this.legendVisible = legendVisible;
	}

	public String getType() {
		return type;
	}

	public void setType(String type) {
		this.type = type;
	}

	public int getWidth() {
		return width;
	}

	public void setWidth(int width) {
		this.width = width;
	}

	public int compareTo(Object o) {
		if (o instanceof ChartConfig) {
			ChartConfig o1 = (ChartConfig) o;
			return this.id.compareTo(o1.id);
		}
		return -1;
	}
}
