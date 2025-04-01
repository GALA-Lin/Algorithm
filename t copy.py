n = int(input())
tasks = []

# 输入每个班级的奖励数据
for _ in range(n):
    A, B = map(int, input().split())
    tasks.append((A, B, A - B))

# 按照 (A_i - B_i) 值降序排列
tasks.sort(key=lambda x: x[2], reverse=True)

# 分配给小蓝和小桥的班级数
num_tasks_blue = n // 2
num_tasks_qiao = n - num_tasks_blue

# 计算小蓝和小桥的总奖励
total_reward = 0
for i in range(num_tasks_blue):
    total_reward += tasks[i][0]  # 小蓝的奖励 A_i
for i in range(num_tasks_blue, n):
    total_reward += tasks[i][1]  # 小桥的奖励 B_i

# 输出最大总奖励
print(total_reward)
