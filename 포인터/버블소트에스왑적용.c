//void bubble_sort(int* p, int n)
//{
//	int i, scan;
//	// 스캔 회수를 제어하기 위한 루프
//	for (scan = 0; scan < n - 1; scan++)
//	{
//		// 인접값 비교 회수를 제어하기 위한 루프
//		for (i = 0; i < n - 1; i++)
//		{
//			// 인접값 비교 및 교환
//			if (p[i] > p[i + 1]) swap(&p[i], &p[i + 1]);
//		}
//	}
//}
//void swap(int* px, int* py)
//{
//	int tmp;
//	tmp = *px;
//	*px = *py;
//	*py = tmp;
//}