class Solution(object):
    def floodFill(self, image, sr, sc, color):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type color: int
        :rtype: List[List[int]]
        """
        queue = [(sr, sc)]
        start_color = image[sr][sc]
        x_max = len(image) - 1
        y_max = len(image[0]) - 1

        if start_color == color:
            return image

        while len(queue) != 0:
            pixel = queue.pop()
            px = pixel[0]
            py = pixel[1]
            if image[px][py] == start_color:
                image[px][py] = color
                if px > 0 and image[px - 1][py] != color:
                    queue.append((px - 1, py))
                if px < x_max and image[px + 1][py] != color:
                    queue.append((px + 1, py))
                if py > 0 and image[px][py - 1] != color:
                    queue.append((px, py - 1))
                if py < y_max and image[px][py + 1] != color:
                    queue.append((px, py + 1))
        
        return image
