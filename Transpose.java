import java.util.*;
public class Transpose {
    public static int[][] transpose(int[][] matrix, int rows, int cols) {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<i;j++) //IT WILL UNTIL THE COLUMNS LESS THAN OF THAT SPECIFIC ROW [DIAGONAL]
            {
                int temp=matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] =temp;
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

        int[][] transposedMatrix = transpose(matrix, rows, cols);
        System.out.println("Transposed Matrix:");
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < rows; j++) {
                System.out.print(transposedMatrix[i][j] + " ");
            }
            System.out.println();
        }    
    }
}