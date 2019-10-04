import java.util.Map;
import java.util.HashMap;

class RomanToInteger {

    private static Map<String, Integer> map = new HashMap<String, Integer>();
    

    public static void main(String[] args) {
        map.put("I", new Integer("1"));
        map.put("V", new Integer("5"));
        map.put("X", new Integer("10"));
        map.put("L", new Integer("50"));
        map.put("C", new Integer("100"));
        map.put("D", new Integer("500"));
        map.put("M", new Integer("1000"));

        int rs = romanToInt("LVIII");
        
        System.out.printf("result is %d\n", rs);
    }

    public static int romanToInt(String s) {
        int len = s.length();
        int rs = 0;
        for(int i = 0; i < len-1; i++) {
            int cur = map.get(String.valueOf(s.charAt(i))).intValue();
            int next = map.get(String.valueOf(s.charAt(i+1))).intValue();
            if (cur >= next) {
                rs += cur;
            } else {
                rs -= cur;
            }
        }

        rs += map.get(String.valueOf(s.charAt(len-1))).intValue();
        return rs;
    }
}
