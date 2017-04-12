#include "pch.h"
#include "OptionalPackageDLL.h"
#include "atlimage.h"
#include "atltypes.h"

// Optional Package Code
__declspec(dllexport) int __cdecl ExampleAPIExport()
{
	return 40;
}

__declspec(dllexport) void __cdecl GrayScale(CImage* pcImage)
{
	int iWidth(pcImage->GetWidth());
	int iHeight(pcImage->GetHeight());

	if (iWidth && iHeight) {
		for (int i = 0; i < iWidth; i++) {
			for (int j = 0; j < iHeight; j++) {
				COLORREF clrOriginal(pcImage->GetPixel(i, j));
				float fR(GetRValue(clrOriginal));
				float fG(GetGValue(clrOriginal));
				float fB(GetBValue(clrOriginal));

				float fWB = sqrt((fR * fR + fG * fG + fB * fB) / 3);
				pcImage->SetPixel(i, j, RGB(fWB, fWB, fWB));
			}
		}
	}
}

