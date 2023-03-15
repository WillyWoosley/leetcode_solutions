class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) {
            return image;
        }

        queue<tuple<int, int>> tofill;
        tofill.push(make_tuple(sr, sc));
        int org_color = image[sr][sc];
        int row_max = image.size() - 1, col_max = image[0].size() - 1;

        while (!tofill.empty()) {
            tuple<int, int> coords = tofill.front();
            int r = get<0>(coords), c = get<1>(coords);
            
            if (image[r][c] == org_color) {
                image[r][c] = color;

                if (r > 0 && image[r-1][c] == org_color) {
                    tofill.push(make_tuple(r-1, c));
                }
                if (r < row_max && image[r+1][c] == org_color) {
                    tofill.push(make_tuple(r+1, c));
                }
                if (c > 0 && image[r][c-1] == org_color) {
                    tofill.push(make_tuple(r, c-1));
                }
                if (c < col_max && image[r][c+1] == org_color) {
                    tofill.push(make_tuple(r, c+1));
                }
            } 

            tofill.pop();
        }

        return image;
    }
};
