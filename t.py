def spiral_fill(n):
    # 创建一个 n x n 的全零矩阵
    matrix = [[0] * n for _ in range(n)]
    num = 1  # 从 1 开始填充
    top, bottom, left, right = 0, n - 1, 0, n - 1
    
    while top <= bottom and left <= right:
        # 向右填充
        for i in range(left, right + 1):
            if top <= i <= bottom:
                matrix[top][i] = num
                num += 1
        top += 1
        
        # 向下填充
        for i in range(top, bottom + 1):
            if left <= i <= right:
                matrix[i][right] = num
                num += 1
        right -= 1
        
        # 向左填充
        for i in range(right, left - 1, -1):
            if top <= i <= bottom:
                matrix[bottom][i] = num
                num += 1
        bottom -= 1
        
        # 向上填充
        for i in range(bottom, top - 1, -1):
            if left <= i <= right:
                matrix[i][left] = num
                num += 1
        left += 1
    
    # 打印矩阵的上三角区域
    for i in range(n):
        for j in range(n):
            if j >= i:
                print(matrix[i][j], end=' ')
        print()

# 示例
n = int(input("请输入矩阵的边长："))
spiral_fill(n)