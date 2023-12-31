#include <stdio.h>

struct NODE {
	unsigned char	c;		// ky tu
	int		freq;	// so lan xuat hien
	bool	used;	// danh dau node da xu ly chua 
	int		nLeft;	// chi so nut con nam ben trai
	int		nRight;	// chi so nut con nam ben phai
};

struct MABIT {
	char*	bits;
	int		soBit;
};

const int MAX_NODE = 256*9;
const int MAX_BIT_LEN = 10000;
NODE	huffTree[MAX_NODE];
MABIT	bangMaBit[256];	


void KhoiTao() {
	for (int i = 0; i < MAX_NODE; i++) {
		huffTree[i].c = i;
		huffTree[i].freq = 0;
		huffTree[i].used = false;
		huffTree[i].nLeft = -1;
		huffTree[i].nRight = -1;
	}
}

void ThongKeTanSoXuatHien(char* tenFile) {	
	FILE* fi = fopen(tenFile, "rt");
	unsigned char c;

	while (1)	{		
		fscanf(fi, "%c", &c);
		if (feof(fi)) {
			break;
		}
		huffTree[c].freq ++; // Ghi ch�: Thao t�c n�y d? l�m g� (nghia l� g�)?		
	}

	fclose(fi);
}

void XuatBangThongKe() {
	printf("Bang thong ke tan suat: \n");
	for (int i = 0; i < 256; i++) {
		if (huffTree[i].freq > 0) {// Ghi ch�: t?i sao c?n ki?m tra di?u ki?n n�y?
			printf("%c: %d\n",i, huffTree[i].freq);
		}
	}
}

bool Tim2PhanTuMin(int &i, int &j, int nNode) {
	i = -1;
	j = -1;

// tim 2 phan tu co trong so nho nhat
	for (int k = 0; k < nNode; k++)
		if (huffTree[k].used == false && huffTree[k].freq > 0)		{ // Ghi ch�: T?i sao c?n ki?m tra 2 di?u ki?n n�y
			if (i == -1) {
				i = k;
			}
			else if (j == -1) {
				j = k;
			}
			else {
				if (huffTree[i].freq > huffTree[j].freq) {
					if (huffTree[k].freq < huffTree[i].freq) {
						i = k;
					}
				}
				else {
					if (huffTree[k].freq < huffTree[j].freq) {
						j = k;
					}
				}
			}
		}
// sap xep lai 2 phan tu de co i: phan tu co trong so nho nhat, j: phan tu co trong so nho nhi	
// co 2 truong hop can doi i,j:
		// huffTree[i].freq > huffTree[j].freq
		// huffTree[i].freq == huffTree[j].freq va (huffTree[i].c > huffTree[j].c)
	if (i != -1 && j!= -1) {
		if ( (huffTree[i].freq > huffTree[j].freq) || ((huffTree[i].freq > huffTree[j].freq) && (huffTree[i].c > huffTree[j].c))) {
			int t = i;
			i = j;
			j = t;
		}
		return true;
	}
	else {
		return false;
	}
}


int TaoCayHuffman() {
	int nNode = 256;
	int i, j;
	bool timThay = false;
	while (true)	{

		// Ghi ch�: bu?c n�y d? l�m g�
		timThay = Tim2PhanTuMin(i, j, nNode);
		if (!timThay) {
			break;
		}

		// Ghi ch�: bu?c n�y d? l�m g�
		huffTree[nNode].c = (huffTree[i].c < huffTree[j].c) ? huffTree[i].c : huffTree[j].c; 
		huffTree[nNode].freq = huffTree[i].freq + huffTree[j].freq;
		huffTree[nNode].nLeft = i;
		huffTree[nNode].nRight = j;
		
		// Ghi ch�: bu?c n�y d? l�m g�
		huffTree[i].used = true;
		huffTree[j].used = true;

		// Ghi ch�: bu?c n�y d? l�m g�
		huffTree[nNode].used = false;
		nNode++;
		
	}
	return nNode - 1; // Ghi ch�: � nghia c?a gi� tr? tr? v??
	
}

void XuatCayHuffman(int node, int tab) {
	if (node == -1) {
		return;
	}
	for (int i = 0; i < tab; i++) {
		printf("\t");
	}
	if (huffTree[node].nLeft == -1 && huffTree[node].nRight == -1)	{
		printf("%c\n", huffTree[node].c);
	}
	else	{
		printf("%c..\n", huffTree[node].c);
		XuatCayHuffman(huffTree[node].nLeft, tab + 1);
		XuatCayHuffman(huffTree[node].nRight, tab + 1);
	}
}

void DuyetCayHuffman(int node, char maBit[], int nMaBit) {
	if (node == -1) {
		return;
	}
	if (huffTree[node].nLeft == -1 && huffTree[node].nRight == -1) {	//Ghi ch�: � nghia c?a di?u ki?n ki?m tra l� g�?	
		bangMaBit[node].soBit = nMaBit;
		bangMaBit[node].bits = new char[nMaBit];
		for (int i = 0; i < nMaBit; i++) {
			bangMaBit[node].bits[i] = maBit[i];
		}
		return;
	}
	else {
		//Ghi ch�: � nghia c?a 2 d�ng l?nh b�n du?i l� g�?
		maBit[nMaBit] = 0;		
		DuyetCayHuffman(huffTree[node].nLeft, maBit, nMaBit + 1);
		
		//Ghi ch�: � nghia c?a 2 d�ng l?nh b�n du?i l� g�?
		maBit[nMaBit] = 1;
		DuyetCayHuffman(huffTree[node].nRight, maBit, nMaBit + 1);
	}
}

void PhatSinhMaBit(int nRoot) { // Ghi ch�: � nghia c?a tham s? nRoot?
	for (int i = 0; i < 256; i++) {
		bangMaBit[i].soBit = 0;
		bangMaBit[i].bits = NULL;
	};
	char maBit[MAX_BIT_LEN/8];
	int nMaBit = 0;

	DuyetCayHuffman(nRoot, maBit, nMaBit);
}

void XuatBangMaBit() {
	for (int i = 0; i < 256; i++)
		if (bangMaBit[i].soBit > 0)	{
			printf("%c: ", i);
			for (int j = 0; j < bangMaBit[i].soBit; j++)
				printf("%d", bangMaBit[i].bits[j]);
			printf("\n");
		}
}

void XuatByte(unsigned char out, int soBitCoNghia) {
	for (int i = 7; i >= 7 - soBitCoNghia + 1; i--) {
		if ((out >> i) & 1) {// Ghi ch�: Thao t�c n�y d? l�m g�?
			printf("1");
		}
		else {
			printf("0");		
		}
	}
}

void MaHoa1KyTu(unsigned char c, unsigned char &out, unsigned char &viTriBit) { //Ghi ch�: � nghia c?a c�c tham s? truy?n v�o?

	for (int i = 0; i < bangMaBit[c].soBit; i++) {
		if (bangMaBit[c].bits[i] == 1) {
			out = out | (1 << viTriBit); // Ghi ch�: Thao t�c n�y d? l�m g�?
		}
		if (viTriBit == 0) { // da du 1 byte, ghi byte do ra file
			viTriBit = 7;
			XuatByte(out, 8);
			out = 0;
		}
		else {
			viTriBit--;
		}
	}
}

void NenHuffman(char* inputFile) {
// BUOC 1: thong ke tan suat xuat hien cua cac ki tu
	KhoiTao();

	ThongKeTanSoXuatHien(inputFile);	

//	XuatBangThongKe();

// BUOC 2: tao cay Huffman
	
	int nRoot = TaoCayHuffman();

//	XuatCayHuffman(nRoot, 0);

// BUOC 3: phat sinh ma bit
	
	PhatSinhMaBit(nRoot);
	
//	XuatBangMaBit();


	unsigned char out = 0;				
	unsigned char soBitCoNghia = 0;		

	unsigned char c;
	unsigned char viTriBit = 7;		
	FILE* fi = fopen(inputFile, "rt");
	while (true) {	
		fscanf(fi, "%c", &c);
		if (feof(fi)) {
			break;
		}
		MaHoa1KyTu(c, out, viTriBit);
	}
	soBitCoNghia = 7 - viTriBit;
	if (soBitCoNghia == 0) {				
		soBitCoNghia = 8;
	}
	else {
		XuatByte(out, soBitCoNghia);
	}

	fclose(fi);
}

int main() {
// nen
	NenHuffman("input.txt");
}
