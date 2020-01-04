import math
import random
import time
import argparse
from pyswagger import App
from pyswagger.contrib.client.requests import Client

class goldPoint:

	def __init__(self):
		self.i = 0
		self.T1 = 0.8
		self.T2 = 1.5
		self.m = 0
		self.W = []
		for i in range(2000):
			self.W.append(0)
		self.X1 = 0
		self.X2 = 0

	def linearRegression(self, a, k, n):
		# init & declare
		w = 0
		b = 0
		nx = 0
		sum = 0
		SUMx_y = 0
		SUMx2 = 0
		SUMx = 0
		SUMy = 0
		aver = 0
		m = 0
		x = 0
		# calculate the mean of history
		for i in range(k + 1 - n, k + 1):
			x = a[i] - aver
			x *= x
			m += x
		m = math.sqrt(m / n)
		for i in range(k - 9, k + 1):
			if ((aver - m) <= a[i]) and (a[i] <= (aver + m)):
				SUMx_y += (a[i] * i)
				SUMx2 += (i * i)
				SUMx += i
				SUMy += a[i]
				++nx
		w = (SUMx_y - SUMx * SUMy / nx) / (SUMx2 - SUMx * SUMx / nx)
		b = SUMy / nx - w * SUMx / nx
		return (k + 1) * w + b

	def PointCentre(self, a, k):
		# init & declare
		t1 = 0
		t2 = 0
		c = 0
		d = 0
		sum = 0
		SUMx_y = 0
		SUMx2 = 0
		SUMx = 0
		SUMy = 0
		aver = 0
		x = 0
		n = 0
		w = 0
		b = 0
		w1 = 0
		w2 = 0
		w3 = 0
		b1 = 0
		b2 = 0
		b3 = 0
		nx = 0
		# calculate
		if (k == 0):
			return a[0] * 0.6
		else if (k == 1):
			t1 = a[0] - a[1]
			t1 *= 0.5
			return a[1] - t1
		else if (k <= 3):
			t1 = a[k - 2] - a[k - 1]
			t1 *= 0.5
			t2 = a[k - 1] - a[k]
			b = t2 / t1
			c = b * b
			return a[k] * c * t2
		else if (k <= 30):
			for i in range(4, k + 1):
				sum += a[i]
				++n
			aver = sum / n
			for i in range(4, k + 1):
				x = a[i] - aver
				x *= x
				self.m += x
			self.m = math.sqrt(self.m / n)
			for i in range(4, k + 1):
				if ((aver - self.m) <= a[i]) and (a[i] <= (aver + self.m)):
					SUMx_y += (a[i] * i)
					SUMx2 += (i * i)
					SUMx += i
					SUMy += a[i]
					++nx
			w = (SUMx_y - SUMx * SUMy / nx) / (SUMx2 - SUMx * SUMx / nx)
			b = SUMy / nx - w * SUMx / nx
			return (w * (k + 1) + b)
		else:
			KPlusOne = []
			KPlusOne.append(self.linearRegression(a, k, 30))
			KPlusOne.append(self.linearRegression(a, k, 25))
			KPlusOne.append(self.linearRegression(a, k, 20))
			KPlusOne.append(self.linearRegression(a, k, 15))
			KPlusOne.append(self.linearRegression(a, k, 10))
			return self.linearRegression(KPlusOne, 4, 5)

	def GanRaoJiLv(self, a, k, PointCentreKPlusOne, m):
		if (a[k] <= (PointCentreKPlusOne - m * 0.6667)):
			return 0.9
		else if (a[k] <= (PointCentreKPlusOne + m * 0.3333)):
			return (PointCentreKPlusOne + m * 0.3333 - a[k]) * 0.9 / m
		else if (a[k] < (PointCentreKPlusOne + 1.8 * m)):
			return 0
		else if (a[k] > PointCentreKPlusOne +T1 * m):
			if (a[k - 1] > PointCentreKPlusOne + T1 * m):
				if (a[k] < PointCentreKPlusOne + T2 * m):
					return 0.5
				else:
					return 0
			else:
				return 0.73
		else:
			return 0

	def Setting_w(self, a, k):
		# init & declare
		doubleSUM = 0
		num = 1
		w = 0
		b = 0
		nx = 0
		sum = 0
		SUMx_y = 0
		SUMx2 = 0
		SUMx = 0
		SUMy = 0
		aver = 0
		x = 0
		m0 = 0
		n = 0
		if (k <= 49):
			n = 0.8 * k
		else:
			n = 40
		for i in range(k + 1 - n, k + 1):
			sum += a[i]
		aver = sum / n
		for i in range(k + 1 - n, k + 1):
			x = a[i] - aver
			x *= x
			m0 += x
		m0 = math.sqrt(m0 / n)
		for i in range(0, n):
			if (a[k - i] >= sum + 0.8 * m0):
				self.W[num] = double(a[k - i] / a[k - i - 1])
				doubleSum += self.W[num] * self.W[num]
				++num
				w += self.W[num] * self.W[num] * self.W[num]
				w /= doubleSUM
		return

	def predict(self, a):
		k = a.len() - 1
		n = self.PointCentre(a, k)
		k = self.GanRaoJiLv(a, k, n, self.m)		# ?
		GanRao = 0
		Tt = random.random()
		self.Setting_w()
		if (Tt <= k):
			GanRao = 1
			self.X2 = 99
			self.X1 = a[k] * w
		else:
			GanRao = 0
			self.X1 = n * 0.9
			self.X2 = n * 1.1
		return (self.X1, self.X2)

def main():
	gp = goldPoint()

	# 初始化 swagger 客户端
	host = 'https://goldennumber.aiedu.msra.cn/'
	jsonpath = '/swagger/v1/swagger.json'
	app = App._create_(host + jsonpath)
	client = Client()

	parser = argparse.ArgumentParser()
	parser.add_argument('--room', type=int, help='Room ID', required=False)
	args = parser.parse_args()
	roomId = args.room

	if roomId is None:
		# 如果参数中没有给出room ID,则要求输入room ID
		roomId = input("Input room id: ")
		try:
			roomId = int(roomId)
		except:
			roomId = 0
			print('Parse room id failed, default join in to room 0')

	userInfoFile = "userinfo.txt"
	userId = "019"
	nickName = None
	try:
		# 使用已存在的玩家
		with open(userInfoFile) as f:
			userId, nickName = f.read().split(',')[:2]
		print('Use an exist player: ' + nickName + '  Id: ' + userId)
	except:
		# 创建一个新的玩家
		userResp = client.request(
			app.op['NewUser'](
				nickName='019'
			))
		assert userResp.status == 200
		user = userResp.data
		userId = user.userId
		nickName = user.nickName
		print('Create a new player: ' + nickName + '  Id: ' + userId)

		with open(userInfoFile, "w") as f:
			f.write("%s,%s" % (userId, nickName))

	print('Room id: ' + str(roomId))

	while True:
		stateResp = client.request(
			app.op['State'](
				uid=userId,
				roomid=roomId
			))
		if stateResp.status != 200:
			print('Network issue, query again after 1 second')
			time.sleep(1)
			continue
		state = stateResp.data
	
		if state.state == 2:
			print('The game has finished')
			break

		if state.state == 1:
			print('The game has not started, query again after 1 second')
			time.sleep(1)
			continue

		if state.hasSubmitted:
			print('Already submitted this round, wait for next round')
			if state.maxUserCount == 0:
				time.sleep(state.leftTime + 1)
			else:
				# 每秒检测一次：当设置了最大用户数量后，当所有用户都已提交信息后，一个回合就应该结束
				time.sleep(1)
			continue

		print('\r\nThis is round ' + str(state.finishedRoundCount + 1))

		todayGoldenListResp = client.request(
			app.op['TodayGoldenList'](
				roomid=roomId
			))
		if todayGoldenListResp.status != 200:
			print('Network issue, query again after 1 second')
			time.sleep(1)
			continue
		todayGoldenList = todayGoldenListResp.data
		if len(todayGoldenList.goldenNumberList) != 0:
			print('Last golden number is: ' + str(todayGoldenList.goldenNumberList[-1]))

		lastRoundResp = client.request(
			app.op['History'](
				roomid=roomId,
				count=1
			))
		if lastRoundResp.status != 200:
			print('Network issue, query again after 1 second')
			time.sleep(1)
			continue
		lastScore = 0
		if len(lastRoundResp.data.rounds) > 0:
			scoreArray = [user for user in lastRoundResp.data.rounds[0].userNumbers if user.userId == userId]
			if len(scoreArray) == 1:
				lastScore = scoreArray[0].score
		print('Last round score: {}'.format(lastScore))

		number1, number2 = gp.predict(todayGoldenList.goldenNumberList)

		if (state.numbers == 2):
			submitRsp = client.request(
				app.op['Submit'](
					uid=userId,
					rid=state.roundId,
					n1=str(number1),
					n2=str(number2)
				))
			if submitRsp.status == 200:
				print('You submit numbers: ' + str(number1) + ', ' + str(number2))
			else:
				print('Error: ' + submitRsp.data.message)
				time.sleep(1)

		else:
			submitRsp = client.request(
				app.op['Submit'](
					uid=userId,
					rid=state.roundId,
					n1=str(number1)
				))
			if submitRsp.status == 200:
				print('You submit number: ' + str(number1))
			else:
				print('Error: ' + submitRsp.data.message)
				time.sleep(1)

if __name__ == '__main__':
	main()
