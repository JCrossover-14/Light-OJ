import java.util.Scanner;

public class Main
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int loop = Integer.parseInt(input.nextLine());
        for (int i = 1; i <= loop; i++) {
            String answer = "Case " + i +": ";
            String theInput = input.nextLine();
            int row = Integer.parseInt(theInput.substring(0,theInput.indexOf(' ')));
            int column = Integer.parseInt(theInput.substring(theInput.indexOf(' ')+1));
            if(row<3||column <3)
            {
                if(row==1||column==1)
                {
                    answer+=Math.max(row,column);
                }
                else if (row ==2 &&column ==2)
                {
                    answer+="4";
                }
                else if (row == 2||column==2)
                {
                    
                    if(Math.max(row,column)%4==0)
                    {
                        answer+=((row*column)/2);
                    }
                    else if (Math.max(row,column)%4==1)
                    {
                        answer+=((Math.max(row,column)/4)*4+2);
                    }
                    else
                    {
                        answer+=(Math.max(row,column)/4)*4+4;
                    }
                    
                }

            }
            else
            {
                answer+=(int)Math.ceil((row*column)/2.0);
            }

            System.out.println(answer);
        }


    }
}