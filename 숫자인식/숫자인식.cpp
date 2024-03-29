#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <string.h>

void setcolor(unsigned short text, unsigned short back) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}


struct Spot {
	float x;
	float y;
	bool exist;
};

struct Spot spot[7] = {
	{ 22, 14 , false },//spot1
	{ 6,22,false },//spot2
	{ 38,17,false },//spot3
	{ 2,25,false },//spot4
	{ 5,39,false },//spot5
	{ 20,38,false },//spot6
	{ 39,44,false },//spot7

};

float fullX = 42;
float fullY = 62;
float lx = 0, sx = 200;
float ly = 0, sy = 200;
float w = 0; //자른 사각형의 width,height
float h = 0;
CvScalar s;

int spotnum = 7;



/*
{ 24, 2, false },//spot1
{ 5,22,false },//spot2
{ 38,17,false },//spot3
{ 2,25,false },//spot4
{ 5,39,false },//spot5
{ 20,38,false },//spot6
{ 39,44,false },//spot7
{ 22,61,false },//spot8
*/
/*{ 24, 2, false },//spot1
{ 5,21,false },//spot2
{ 38,17,false },//spot3
{ 1,25,false },//spot4
{ 5,39,false },//spot5
{ 20,38,false },//spot6
{ 39,44,false },//spot7
{ 22,61,false },//spot8
*/
void getframe(IplImage * img)
{
	for (int i = 0; i < 200; i++)
		for (int j = 0; j < 200; j++)
		{
			s = cvGet2D(img, j, i);
			if (s.val[0] != 255)  // 흰색이 아닐 때
			{
				if (i > lx)    //오른쪽 외곽선 찾기
					lx = i;
				if (i < sx)  // 왼쪽 외곽선 찾기
					sx = i;
				if (j > ly)  //위 외곽선 찾기
					ly = j;
				if (j < sy)   //아래 외곽선 찾기
					sy = j;
			}
		}
	w = lx - sx;//0부터 시작임
	h = ly - sy;
}

void checkspot(IplImage * img)
{
	for (int i = 0; i < spotnum; i++)
	{
		s = cvGet2D(img, sy + (spot[i].y * h) / fullY, sx + (spot[i].x * w) / fullX);

		if (s.val[0] != 255)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					cvSet2D(img, sy + j + spot[i].y * h / fullY, sx + k + spot[i].x * w / fullX, cvScalar(10, 10, 255));

				}
			}

			spot[i].exist = true;
		}
		else
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					cvSet2D(img, sy + j + spot[i].y * h / fullY, sx + k + spot[i].x * w / fullX, cvScalar(255, 10, 10));

				}
			}
		}

		if (spot[i].exist == true)
			printf("%d 번 트루 (1)\n", i + 1);
		else
			printf("%d 번 폴스 (0)\n", i + 1);

	}
}


int getspotnum[11];
int checknum0();
int checknum1S();
int checknum1G();
int checknum2();
int checknum3();
int checknum4();
int checknum5();
int checknum6();
int checknum7();
int checknum8();
int checknum9();

int getspot()
{

	getspotnum[0] = checknum0();

	getspotnum[1] = checknum1S();

	getspotnum[2] = checknum1G();

	getspotnum[3] = checknum2();

	getspotnum[4] = checknum3();

	getspotnum[5] = checknum4();

	getspotnum[6] = checknum5();

	getspotnum[7] = checknum6();

	getspotnum[8] = checknum7();

	getspotnum[9] = checknum8();

	getspotnum[10] = checknum9();


	int biggestnum = 0;
	int biggestcnt = 0;

	for (int i = 0; i<11; i++)
	{
		if (biggestcnt < getspotnum[i])
		{
			biggestcnt = getspotnum[i];
			biggestnum = i;
		}
	}

	if (biggestnum > 1)
	{
		biggestnum = biggestnum - 1;
	}

	return biggestnum;

}

int main()
{
	IplImage * img;
	char fileName[15];
	char cDrive[30] = "C:\\";
	printf("사진 경로를 입력하세요 : ");
	scanf("%s", fileName);
	printf("\n");

	strcat(cDrive, fileName);

	img = cvLoadImage(cDrive);

	//img = cvLoadImage("C:\\숫자\\굴림\\5.png");
	getframe(img);

	//printf("lx=%f  sx=%f  ly=%f  sy=%f\n", lx, sx, ly, sy);
	//printf("w=%f , h=%f\n", w, h);
	checkspot(img);

	int result;
	result = getspot();

	printf("\n결과는 숫자 \' %d \' 입니다.\n", result);




	cvShowImage("Module", img);
	cvWaitKey();

	cvDestroyWindow("HelloCV");
	cvReleaseImage(&img);

	return 0;
}


int checknum0()
{
	int cnt = 0;
	printf("\n");
	printf("0 : ");
	if (spot[0].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");
	if (spot[1].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[2].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[3].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[4].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[5].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[6].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1\n");
		setcolor(15, 0);
	}
	else
		printf("1\n");

	printf("overlap count : %d spot(s) \n", cnt);
	return cnt;
}

int checknum1S()
{
	int cnt = 0;
	printf("\n(신명조)\n");
	printf("1 : ");
	if (spot[0].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[1].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[2].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[3].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[4].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[5].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[6].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0\n");
		setcolor(15, 0);
	}
	else
		printf("0\n");
	printf("overlap count : %d spot(s) \n", cnt);
	return cnt;

}

int checknum1G()
{
	int cnt = 0;
	printf("\n(굴림, 견고딕)\n");
	printf("1 : ");
	if (spot[0].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[1].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[2].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[3].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[4].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[5].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[6].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1\n");
		setcolor(15, 0);
	}
	else
		printf("1\n");

	printf("overlap count : %d spot(s) \n", cnt);
	return cnt;

}

int checknum2()
{
	int cnt = 0;
	printf("\n");
	printf("2 : ");
	if (spot[0].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[1].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[2].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[3].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[4].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[5].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[6].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0\n");
		setcolor(15, 0);
	}
	else
		printf("0\n");

	printf("overlap count : %d spot(s) \n", cnt);
	return cnt;
}

int checknum3()
{

	int cnt = 0;
	printf("\n");
	printf("3 : ");
	if (spot[0].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[1].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[2].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[3].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[4].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[5].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[6].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1\n");
		setcolor(15, 0);
	}
	else
		printf("1\n");

	printf("overlap count : %d spot(s) \n", cnt);
	return cnt;
}

int checknum4()
{

	int cnt = 0;
	printf("\n");
	printf("4 : ");
	if (spot[0].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[1].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[2].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[3].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[4].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[5].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[6].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1\n");
		setcolor(15, 0);
	}
	else
		printf("1\n");

	printf("overlap count : %d spot(s) \n", cnt);
	return cnt;
}

int checknum5()
{

	int cnt = 0;
	printf("\n");
	printf("5 : ");
	if (spot[0].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[1].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[2].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[3].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[4].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[5].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[6].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1\n");
		setcolor(15, 0);
	}
	else
		printf("1\n");

	printf("overlap count : %d spot(s) \n", cnt);
	return cnt;
}


int checknum6()
{

	int cnt = 0;
	printf("\n");
	printf("6 : ");
	if (spot[0].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[1].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[2].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[3].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[4].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[5].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[6].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1\n");
		setcolor(15, 0);
	}
	else
		printf("1\n");

	printf("overlap count : %d spot(s) \n", cnt);
	return cnt;
}

int checknum7()
{

	int cnt = 0;
	printf("\n");
	printf("7 : ");
	if (spot[0].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[1].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[2].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[3].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[4].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[5].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[6].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0\n");
		setcolor(15, 0);
	}
	else
		printf("0\n");

	printf("overlap count : %d spot(s) \n", cnt);
	return cnt;
}

int checknum8()
{

	int cnt = 0;
	printf("\n");
	printf("8 : ");
	if (spot[0].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[1].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[2].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[3].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[4].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[5].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[6].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1\n");
		setcolor(15, 0);
	}
	else
		printf("1\n");

	printf("overlap count : %d spot(s) \n", cnt);
	return cnt;
}

int checknum9()
{

	int cnt = 0;
	printf("\n");
	printf("9 : ");
	if (spot[0].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[1].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[2].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[3].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[4].exist == false)
	{
		cnt++;
		setcolor(12, 0);
		printf("0 ");
		setcolor(15, 0);
	}
	else
		printf("0 ");

	if (spot[5].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1 ");
		setcolor(15, 0);
	}
	else
		printf("1 ");

	if (spot[6].exist == true)
	{
		cnt++;
		setcolor(12, 0);
		printf("1\n");
		setcolor(15, 0);
	}
	else
		printf("1\n");

	printf("overlap count : %d spot(s) \n", cnt);
	return cnt;
}
