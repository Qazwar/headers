typedef struct _RTL_AVL_TREE
{
  /* 0x0000 */ struct _RTL_BALANCED_NODE* Root;
} RTL_AVL_TREE, *PRTL_AVL_TREE; /* size: 0x0004 */

typedef struct _MMSUBSECTION_FLAGS
{
  struct /* bitfield */
  {
    /* 0x0000 */ unsigned short SubsectionAccessed : 1; /* bit position: 0 */
    /* 0x0000 */ unsigned short Protection : 5; /* bit position: 1 */
    /* 0x0000 */ unsigned short StartingSector4132 : 10; /* bit position: 6 */
  }; /* bitfield */
  struct /* bitfield */
  {
    /* 0x0002 */ unsigned short SubsectionStatic : 1; /* bit position: 0 */
    /* 0x0002 */ unsigned short GlobalMemory : 1; /* bit position: 1 */
    /* 0x0002 */ unsigned short DirtyPages : 1; /* bit position: 2 */
    /* 0x0002 */ unsigned short OnDereferenceList : 1; /* bit position: 3 */
    /* 0x0002 */ unsigned short SectorEndOffset : 12; /* bit position: 4 */
  }; /* bitfield */
} MMSUBSECTION_FLAGS, *PMMSUBSECTION_FLAGS; /* size: 0x0004 */

typedef struct _SUBSECTION
{
  /* 0x0000 */ struct _CONTROL_AREA* ControlArea;
  /* 0x0004 */ struct _MMPTE* SubsectionBase;
  /* 0x0008 */ struct _SUBSECTION* NextSubsection;
  union
  {
    /* 0x000c */ struct _MI_FILE_EXTENTS* FileExtents;
    /* 0x000c */ struct _RTL_AVL_TREE GlobalPerSessionHead;
    /* 0x000c */ struct _MI_PER_SESSION_PROTOS* SessionDriverProtos;
  }; /* size: 0x0004 */
  union // _TAG_UNNAMED_91
  {
    union
    {
      /* 0x0010 */ unsigned long LongFlags;
      /* 0x0010 */ struct _MMSUBSECTION_FLAGS SubsectionFlags;
    }; /* size: 0x0004 */
  } /* size: 0x0004 */ u;
  /* 0x0014 */ unsigned long StartingSector;
  /* 0x0018 */ unsigned long NumberOfFullSectors;
  /* 0x001c */ unsigned long PtesInSubsection;
  union // _TAG_UNNAMED_92
  {
    /* 0x0020 */ unsigned long NumberOfChildViews;
  } /* size: 0x0004 */ u1;
  union
  {
    /* 0x0024 */ unsigned long UnusedPtes;
    /* 0x0024 */ unsigned long AlignmentNoAccessPtes;
  }; /* size: 0x0004 */
} SUBSECTION, *PSUBSECTION; /* size: 0x0028 */

typedef struct _RTL_BALANCED_NODE
{
  union
  {
    /* 0x0000 */ struct _RTL_BALANCED_NODE* Children[2];
    struct
    {
      /* 0x0000 */ struct _RTL_BALANCED_NODE* Left;
      /* 0x0004 */ struct _RTL_BALANCED_NODE* Right;
    }; /* size: 0x0008 */
  }; /* size: 0x0008 */
  union
  {
    /* 0x0008 */ unsigned char Red : 1; /* bit position: 0 */
    /* 0x0008 */ unsigned char Balance : 2; /* bit position: 0 */
    /* 0x0008 */ unsigned long ParentValue;
  }; /* size: 0x0004 */
} RTL_BALANCED_NODE, *PRTL_BALANCED_NODE; /* size: 0x000c */

typedef struct _LIST_ENTRY
{
  /* 0x0000 */ struct _LIST_ENTRY* Flink;
  /* 0x0004 */ struct _LIST_ENTRY* Blink;
} LIST_ENTRY, *PLIST_ENTRY; /* size: 0x0008 */

typedef struct _MSUBSECTION
{
  /* 0x0000 */ struct _SUBSECTION Core;
  /* 0x0028 */ struct _RTL_BALANCED_NODE SubsectionNode;
  /* 0x0034 */ struct _LIST_ENTRY DereferenceList;
  /* 0x003c */ unsigned long NumberOfMappedViews;
  /* 0x0040 */ unsigned long NumberOfPfnReferences;
} MSUBSECTION, *PMSUBSECTION; /* size: 0x0044 */

