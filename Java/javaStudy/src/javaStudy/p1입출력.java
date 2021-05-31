import java.io.*;
import java.util.*;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));//�Է¿�
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));//��¿�

    public static void sol1() throws IOException 
    {
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int sum = 0;
        long mul = 1; // c++ long long
        //2^63
        for(int i = 0; i < n; i++)
        {
            int temp = Integer.parseInt(st.nextToken());
            sum += temp;
            mul *= temp;
        }
        bw.write(sum + " " + mul);
    }

    public static void sol2()  throws IOException 
    {
        int n = Integer.parseInt(br.readLine());
        int max_len = Integer.MIN_VALUE; // ū�� : ���������� Ŀ������
        int min_len = Integer.MAX_VALUE; // ������ : ū������ �۾�������
        String max_str = "";
        String min_str = "";
        for(int i = 0; i < n; i++)
        {
            String temp = br.readLine();
            if(max_len < temp.length())
            {
                max_len = temp.length();
                max_str = temp;
            }
            if(min_len > temp.length())
            {
                min_len = temp.length();
                min_str = temp;
            }
        }
        bw.write(max_str +"\n" + min_str);
    }
    public static void sol3()  throws IOException 
    {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int row = Integer.parseInt(st.nextToken());
        int col = Integer.parseInt(st.nextToken());
        int min_num = Integer.MAX_VALUE;
        int min_cnt = 0;
        for(int i = 0; i < row; i++)
        {
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j < col; j++)
            {
                int temp = Integer.parseInt(st.nextToken());
                if(temp < min_num)
                {
                    min_num = temp;
                    min_cnt = 1;
                }
                else if(temp == min_num)
                {
                    min_cnt++;
                }
            }
        }
        bw.write(min_num + "\n" + min_cnt + "��");
    }
    public static void main(String[] args) throws IOException {
        int type = Integer.parseInt(br.readLine());
        if(type == 1) sol1();
        else if(type == 2) sol2();
        else if(type == 3) sol3();
        br.close();
        bw.close(); 
    }