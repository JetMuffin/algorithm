/*
** feched by JetMuffin's crawler
** author: chen9434 (JetMuffin)
** http://acm.hdu.edu.cn/viewcode.php?rid=13824428
*/

import java.math.BigInteger;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int cnt = 0;
        while(t > 0){
            t--;
            cnt++;
            int n = sc.nextInt();
            BigInteger base = BigInteger.valueOf(32);
            BigInteger ans = BigInteger.valueOf(1);
            for(int i = 0 ; i < n; i++){
                ans = ans.multiply(base);
            }
            System.out.println("Case #" + cnt +": "+ans);
        }
    }
}    
