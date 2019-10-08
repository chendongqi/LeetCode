class Solution {

    public String longestCommonPrefix(String[] strs) {
        // calculate min String size in strs
        if (strs.length <= 0) {
            return "";
        }
        int min_size = strs[0].length();
        for (int i = 1; i < strs.length; i++) {
            if (min_size > strs[i].length()) {
                min_size = strs[i].length();
            }
        }
        
        String comm = "";
        // choose a longest tmp str maybe the result
        for (int i = min_size; i > 0; i--) {
            String tmp_comm = strs[0].substring(0, i);
            int j;
            for (j = 1; j < strs.length; j++) {
                // check the tmp str for every strs, if not equal, choose next one
                if (!tmp_comm.equals(strs[j].substring(0, i))) {
                    break;
                }
            }
            // found
            if (j >= strs.length) {
                comm = tmp_comm;
                break;
            }
        }
        
        return comm;
    }
}
