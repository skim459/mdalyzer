/***************************************************************************
 *cr                                                                       
 *cr            (C) Copyright 1995-2001 The Board of Trustees of the           
 *cr                        University of Illinois                       
 *cr                         All Rights Reserved                        
 *cr                                                                   
 ***************************************************************************/

/***************************************************************************
 * RCS INFORMATION:
 *
 *      $RCSfile: ReadDCD.h,v $
 *      $Author: saam $        $Locker:  $                $State: Exp $
 *      $Revision: 1.4 $      $Date: 2004/05/16 08:04:45 $
 *
 ***************************************************************************
 * DESCRIPTION:
 *
 * C routines to read and write binary DCD files (which use the goofy
 * FORTRAN UNFORMATTED format).  These routines are courtesy of
 * Mark Nelson (autographs available upon request and $1 tip).
 *
 ***************************************************************************/
#ifndef READ_DCD_H
#define READ_DCD_H

#include <stdio.h>

/*  DEFINE ERROR CODES THAT MAY BE RETURNED BY DCD ROUTINES		*/
#define DCD_DNE		-2	/*  DCD file does not exist		*/
#define DCD_OPENFAILED	-3	/*  Open of DCD file failed		*/
#define DCD_BADREAD 	-4	/*  read call on DCD file failed	*/
#define DCD_BADEOF	-5	/*  premature EOF found in DCD file	*/
#define DCD_BADFORMAT	-6	/*  format of DCD file is wrong		*/
#define DCD_FILEEXISTS  -7	/*  output file already exists		*/
#define DCD_BADMALLOC   -8	/*  malloc failed			*/

/*			FUNCTION ALLUSIONS				*/
FILE * open_dcd_read(const char *);  /*  Open a DCD file for reading 	*/
int read_dcdheader(FILE *, int*, int*, int*, int*, double*, int*, int**, int*, int*);	
				/*  Read the DCD header			*/
int read_dcdstep(FILE *, int, float*, float*, float*, int, int, int*, int, int);	
				/*  Read a timestep's values		*/
int skip_one_frame(FILE * fd, int N, int num_fixed, int first, int reverseEndian, int charmm);

FILE * open_dcd_write(char *);  /*  Open a DCD file for writing		*/
int write_dcdstep(FILE *, int, float *, float *, float *);
				/*  Write out a timesteps values	*/
int write_dcdstep(FILE * fd, int N, int num_fixed, int *indexes,
                  const float *X, const float *Y, const float *Z);
                                /*  Write out a timesteps values	*/
int write_dcdheader(FILE *, char*, int, int, int, int, double);	
				/*  Write a dcd header			*/
void close_dcd_read(FILE *, int, int *);
				/*  Close a dcd file open for reading   */
void close_dcd_write(FILE *);	/*  Close a dcd file open for writing   */

int* reverseFourByteWord(int* ); /* revert 4 byte word byteorder */
int* reverseEightByteDouble(int* ); /* revert 8 byte word byteorder */

#endif /* ! DCDLIB_H */

/* These defines are necessary to support CHARMm DCD files. See
   comments in ReadDCD.C, in read_dcdheader(). */
#define DCD_IS_CHARMM 		0x01
#define DCD_HAS_4DIMS		0x02
#define DCD_HAS_EXTRA_BLOCK	0x04

