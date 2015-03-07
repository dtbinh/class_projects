import java.awt.Color;

public class Glass {

    public static void main (String[] args) {

	/**image being processed*/

	Picture pic1 = new Picture(args[0]);

	int width = pic1.width();
	int height = pic1.height();
	Picture pic = new Picture(width, height);

	for (int i = 0; i < width; i ++){
	    for (int j = 0; j < height; j++){
		
		int ix = ((int)(Math.random() * 10 - 5))+i;
		int jy = ((int)(Math.random() * 10 - 5))+j;

		if (ix >= width || ix < 0)
		    ix = i;
		if (jy >= height || jy < 0)
		    jy = j;

		Color c1 = pic1.get(ix,jy);

		pic.set(i,j,c1);

	    }
	}
	pic.show();
    }
}