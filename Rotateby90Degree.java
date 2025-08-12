import java.util.*;
class Rotateby90Degree
{
    public static int[][] rotate(int matrix[][],int rows,int cols)
    {
        /*for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rotatedMatrix[j][rows - 1 - i] = matrix[i][j];
            }
        }*/
        //the above commented code is the optimal solution as it directly 
        //rotates the matrix by 90 degrees without transposing it first.
        //but here we will use the transpose method to rotate the matrix by 90 degrees.
        //first we will transpose the matrix and then reverse
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<i;j++) //IT WILL RUN UNTIL THE COLUMNS LESS THAN OF THAT SPECIFIC ROW [DIAGONAL]
            {
                int temp=matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] =temp;
            }
        }
        //after transposing the matrix we will reverse the rows of the matrix
        for(int i=0;i<rows;i++)
        {   
            //Collections.reverse(Arrays.asList(matrix[i]));
            //or we can use the below code to reverse the row;
            int start = 0;
            int end = cols - 1;
            while (start < end) {
                int temp = matrix[i][start];
                matrix[i][start] = matrix[i][end];
                matrix[i][end] = temp;
                start++;
                end--;
            }
        }
        return matrix;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the number of rows: ");
        int rows = scanner.nextInt();
        System.out.print("Enter the number of columns: ");
        int cols = scanner.nextInt();

        int[][] matrix = new int[rows][cols];
        System.out.println("Enter the elements of the matrix:");
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = scanner.nextInt();
            }
        }

        int[][] rotatedMatrix = rotate(matrix, rows, cols);
        System.out.println("Rotated by 90 Degree Matrix:");
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                System.out.print(rotatedMatrix[i][j] + " ");
            }
            System.out.println();
        }    
    }
}