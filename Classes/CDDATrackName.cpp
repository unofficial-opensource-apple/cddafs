//���������������������������������������������������������������������������
//	Includes
//���������������������������������������������������������������������������

#include <CoreServices/CoreServices.h>
#include <CoreFoundation/CoreFoundation.h>
#include <sys/param.h>
#include <sys/types.h>
#include <unistd.h>

// private includes
#include "CDDATrackName.h"


//���������������������������������������������������������������������������
//	Macros
//���������������������������������������������������������������������������

#define DEBUG 0

#if DEBUG
#define PRINT(x)	printf x
#else
#define PRINT(x)
#endif


//���������������������������������������������������������������������������
//	� Constructor													[PUBLIC]
//���������������������������������������������������������������������������

CDDATrackName::CDDATrackName ( void )
{
	
	PRINT ( ( "CDDATrackName constructor called\n" ) );
	
	fCFBundleRef = CFBundleGetBundleWithIdentifier ( CFSTR ( "com.apple.filesystems.util.cddafs" ) );	
	
	#if DEBUG
	CFShow ( fCFBundleRef );
	#endif
	
}


//���������������������������������������������������������������������������
//	� Destructor												[PROTECTED]
//���������������������������������������������������������������������������

CDDATrackName::~CDDATrackName ( void )
{
	
	PRINT ( ( "CDDATrackName destructor called\n" ) );	
	
	#if DEBUG
	CFShow ( fCFBundleRef );
	#endif
	
	fCFBundleRef = 0;
	
}


//���������������������������������������������������������������������������
//	� Init															[PUBLIC]
//���������������������������������������������������������������������������

SInt32
CDDATrackName::Init ( const char * bsdDevNode, const void * TOCData )
{
	return 0;
}


//���������������������������������������������������������������������������
//	� GetArtistName													[PUBLIC]
//���������������������������������������������������������������������������

CFStringRef
CDDATrackName::GetArtistName ( void )
{
	
	CFStringRef		artistString = 0;

	PRINT ( ( "CDDATrackName::GetArtistName\n" ) );
	
	artistString = CFCopyLocalizedStringFromTableInBundle ( CFSTR ( "Artist" ),
															CFSTR ( "Localizable" ),
															fCFBundleRef,
															CFSTR ( "Artist" ) );
	
	#if DEBUG
	CFShow ( artistString );
	#endif
	
	return artistString;
	
}


//���������������������������������������������������������������������������
//	� GetAlbumName													[PUBLIC]
//���������������������������������������������������������������������������

CFStringRef
CDDATrackName::GetAlbumName ( void )
{
	
	CFStringRef		albumString = 0;
	
	albumString = CFCopyLocalizedStringFromTableInBundle ( 	CFSTR ( "Title" ),
															CFSTR ( "Localizable" ),
															fCFBundleRef,
															CFSTR ( "Title" ) );
	
	#if DEBUG
	CFShow (  albumString );
	#endif
	
	return albumString;
	
}


//���������������������������������������������������������������������������
//	� GetTrackName													[PUBLIC]
//���������������������������������������������������������������������������

CFStringRef
CDDATrackName::GetTrackName ( UInt8 trackNumber )
{
	
	CFStringRef		trackString = 0;
	
	trackString = CFCopyLocalizedStringFromTableInBundle ( 	CFSTR ( "Audio Track" ),
															CFSTR ( "Localizable" ),
															fCFBundleRef,
															CFSTR ( "Audio Track" ) );
	
	#if DEBUG
	CFShow (  trackString );
	#endif
	
	return trackString;
	
}


//���������������������������������������������������������������������������
//	� GetSeparatorString											[PUBLIC]
//���������������������������������������������������������������������������

CFStringRef
CDDATrackName::GetSeparatorString ( void )
{
	
	CFStringRef		sepString = 0;
	
	sepString = CFCopyLocalizedStringFromTableInBundle ( 	CFSTR ( "Separator" ),
															CFSTR ( "Localizable" ),
															fCFBundleRef,
															CFSTR ( "Separator" ) );
	
	return sepString;
	
}


//���������������������������������������������������������������������������
//					End				Of			File
//���������������������������������������������������������������������������