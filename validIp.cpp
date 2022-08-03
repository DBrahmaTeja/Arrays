int isValid(string s)
{
    // code here
    int dot_cnt = 0, val = 0, temp = 0;
    string temp_str = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '.' and (s[i] < '0' or s[i] > '9'))
            return 0;
        if (dot_cnt > 3)
            return 0;
        else if (s[i] == '.')
        {
            dot_cnt++;
            int lead_zeros = 0;
            for (int i = 0; i < temp_str.size(); i++)
            {
                if (temp_str[i] == '0')
                    lead_zeros++;
                else
                    break;
            }
            if (lead_zeros > 1 or (lead_zeros == 1 and temp_str.size() != 1))
                return 0;
            if (val == 0 and temp != 1)
                return 0;
            if (!(val >= 0 and val <= 255))
                return 0;
            temp = 0;
            val = 0;
            temp_str = "";
        }
        else
        {
            temp++;
            temp_str += s[i];
            val = val * 10 + s[i] - '0';
        }
    }
    int lead_zeros = 0;
    for (int i = 0; i < temp_str.size(); i++)
    {
        if (temp_str[i] == '0')
            lead_zeros++;
        else
            break;
    }
    if (lead_zeros > 1 or (lead_zeros == 1 and temp_str.size() != 1))
        return 0;
    if (dot_cnt != 3)
        return 0;
    if (val == 0 and temp != 1)
        return 0;
    if (!(val >= 0 and val <= 255))
        return 0;
    return 1;
}