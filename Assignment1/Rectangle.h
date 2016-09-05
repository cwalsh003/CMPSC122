class Rectangle
{
	private:
		int width;
		int length;
	public:
	   Rectangle();
	   Rectangle(int l, int w);
	   void setWidth(int w);
	   void setLength(int l);
	   int getWidth() const;
	   int getLength() const;
	   int calcArea() const;
	   int calcParam() const;

};