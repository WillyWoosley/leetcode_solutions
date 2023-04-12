class Solution {
public:
    string simplifyPath(string path) {
        stack<string> path_comp;

        for (int i = 0; i < path.length(); i++) {
            if (path[i] != '/') {
                string part_path = "";
                
                while (i < path.length() && path[i] != '/') {
                    part_path.push_back(path[i]);
                    i++;    
                }

                if (part_path == ".") {
                    continue;
                } else if (part_path == "..") {
                    if (!path_comp.empty()) {
                        path_comp.pop();
                    }
                } else {
                    path_comp.push(part_path);
                }
            }
        }

        string canonical = "";
        while (!path_comp.empty()) {
            canonical = "/" + path_comp.top() + canonical;
            path_comp.pop();        
        }

        if (canonical.length() == 0) {
            return "/";
        } else {
            return canonical;
        }
    }
};
