typedef union _LARGE_INTEGER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned long LowPart;
      /* 0x0004 */ long HighPart;
    }; /* size: 0x0008 */
    struct // _TAG_UNNAMED_4
    {
      /* 0x0000 */ unsigned long LowPart;
      /* 0x0004 */ long HighPart;
    } /* size: 0x0008 */ u;
    /* 0x0000 */ __int64 QuadPart;
  }; /* size: 0x0008 */
} LARGE_INTEGER, *PLARGE_INTEGER; /* size: 0x0008 */

typedef struct _LIST_ENTRY
{
  /* 0x0000 */ struct _LIST_ENTRY* Flink;
  /* 0x0004 */ struct _LIST_ENTRY* Blink;
} LIST_ENTRY, *PLIST_ENTRY; /* size: 0x0008 */

typedef struct _EX_FAST_REF
{
  union
  {
    /* 0x0000 */ void* Object;
    /* 0x0000 */ unsigned long RefCnt : 3; /* bit position: 0 */
    /* 0x0000 */ unsigned long Value;
  }; /* size: 0x0004 */
} EX_FAST_REF, *PEX_FAST_REF; /* size: 0x0004 */

typedef struct _EX_PUSH_LOCK
{
  union
  {
    struct /* bitfield */
    {
      /* 0x0000 */ unsigned long Locked : 1; /* bit position: 0 */
      /* 0x0000 */ unsigned long Waiting : 1; /* bit position: 1 */
      /* 0x0000 */ unsigned long Waking : 1; /* bit position: 2 */
      /* 0x0000 */ unsigned long MultipleShared : 1; /* bit position: 3 */
      /* 0x0000 */ unsigned long Shared : 28; /* bit position: 4 */
    }; /* bitfield */
    /* 0x0000 */ unsigned long Value;
    /* 0x0000 */ void* Ptr;
  }; /* size: 0x0004 */
} EX_PUSH_LOCK, *PEX_PUSH_LOCK; /* size: 0x0004 */

typedef struct _DISPATCHER_HEADER
{
  union
  {
    struct
    {
      /* 0x0000 */ unsigned char Type;
      union
      {
        /* 0x0001 */ unsigned char TimerControlFlags;
        struct /* bitfield */
        {
          /* 0x0001 */ unsigned char Absolute : 1; /* bit position: 0 */
          /* 0x0001 */ unsigned char Coalescable : 1; /* bit position: 1 */
          /* 0x0001 */ unsigned char KeepShifting : 1; /* bit position: 2 */
          /* 0x0001 */ unsigned char EncodedTolerableDelay : 5; /* bit position: 3 */
        }; /* bitfield */
        /* 0x0001 */ unsigned char Abandoned;
        struct
        {
          /* 0x0001 */ unsigned char Signalling;
          union
          {
            /* 0x0002 */ unsigned char ThreadControlFlags;
            struct /* bitfield */
            {
              /* 0x0002 */ unsigned char CpuThrottled : 1; /* bit position: 0 */
              /* 0x0002 */ unsigned char CycleProfiling : 1; /* bit position: 1 */
              /* 0x0002 */ unsigned char CounterProfiling : 1; /* bit position: 2 */
              /* 0x0002 */ unsigned char Reserved : 5; /* bit position: 3 */
            }; /* bitfield */
            /* 0x0002 */ unsigned char Hand;
            struct
            {
              /* 0x0002 */ unsigned char Size;
              union
              {
                /* 0x0003 */ unsigned char TimerMiscFlags;
                struct /* bitfield */
                {
                  /* 0x0003 */ unsigned char Index : 1; /* bit position: 0 */
                  /* 0x0003 */ unsigned char Processor : 5; /* bit position: 1 */
                  /* 0x0003 */ unsigned char Inserted : 1; /* bit position: 6 */
                  /* 0x0003 */ volatile unsigned char Expired : 1; /* bit position: 7 */
                }; /* bitfield */
                /* 0x0003 */ unsigned char DebugActive;
                struct /* bitfield */
                {
                  /* 0x0003 */ unsigned char ActiveDR7 : 1; /* bit position: 0 */
                  /* 0x0003 */ unsigned char Instrumented : 1; /* bit position: 1 */
                  /* 0x0003 */ unsigned char Reserved2 : 4; /* bit position: 2 */
                  /* 0x0003 */ unsigned char UmsScheduled : 1; /* bit position: 6 */
                  /* 0x0003 */ unsigned char UmsPrimary : 1; /* bit position: 7 */
                }; /* bitfield */
                /* 0x0003 */ unsigned char DpcActive;
              }; /* size: 0x0001 */
            }; /* size: 0x0002 */
          }; /* size: 0x0002 */
        }; /* size: 0x0003 */
      }; /* size: 0x0003 */
    }; /* size: 0x0004 */
    /* 0x0000 */ volatile long Lock;
  }; /* size: 0x0004 */
  /* 0x0004 */ long SignalState;
  /* 0x0008 */ struct _LIST_ENTRY WaitListHead;
} DISPATCHER_HEADER, *PDISPATCHER_HEADER; /* size: 0x0010 */

typedef struct _KGATE
{
  /* 0x0000 */ struct _DISPATCHER_HEADER Header;
} KGATE, *PKGATE; /* size: 0x0010 */

typedef struct _KGUARDED_MUTEX
{
  /* 0x0000 */ volatile long Count;
  /* 0x0004 */ struct _KTHREAD* Owner;
  /* 0x0008 */ unsigned long Contention;
  /* 0x000c */ struct _KGATE Gate;
  union
  {
    struct
    {
      /* 0x001c */ short KernelApcDisable;
      /* 0x001e */ short SpecialApcDisable;
    }; /* size: 0x0004 */
    /* 0x001c */ unsigned long CombinedApcDisable;
  }; /* size: 0x0004 */
} KGUARDED_MUTEX, *PKGUARDED_MUTEX; /* size: 0x0020 */

typedef struct _KEVENT
{
  /* 0x0000 */ struct _DISPATCHER_HEADER Header;
} KEVENT, *PKEVENT; /* size: 0x0010 */

typedef struct _PRIVATE_CACHE_MAP_FLAGS
{
  struct /* bitfield */
  {
    /* 0x0000 */ unsigned long DontUse : 16; /* bit position: 0 */
    /* 0x0000 */ unsigned long ReadAheadActive : 1; /* bit position: 16 */
    /* 0x0000 */ unsigned long ReadAheadEnabled : 1; /* bit position: 17 */
    /* 0x0000 */ unsigned long PagePriority : 3; /* bit position: 18 */
    /* 0x0000 */ unsigned long Available : 11; /* bit position: 21 */
  }; /* bitfield */
} PRIVATE_CACHE_MAP_FLAGS, *PPRIVATE_CACHE_MAP_FLAGS; /* size: 0x0004 */

typedef struct _PRIVATE_CACHE_MAP
{
  union
  {
    /* 0x0000 */ short NodeTypeCode;
    /* 0x0000 */ struct _PRIVATE_CACHE_MAP_FLAGS Flags;
    /* 0x0000 */ unsigned long UlongFlags;
  }; /* size: 0x0004 */
  /* 0x0004 */ unsigned long ReadAheadMask;
  /* 0x0008 */ struct _FILE_OBJECT* FileObject;
  /* 0x0010 */ union _LARGE_INTEGER FileOffset1;
  /* 0x0018 */ union _LARGE_INTEGER BeyondLastByte1;
  /* 0x0020 */ union _LARGE_INTEGER FileOffset2;
  /* 0x0028 */ union _LARGE_INTEGER BeyondLastByte2;
  /* 0x0030 */ unsigned long SequentialReadCount;
  /* 0x0034 */ unsigned long ReadAheadLength;
  /* 0x0038 */ union _LARGE_INTEGER ReadAheadOffset;
  /* 0x0040 */ union _LARGE_INTEGER ReadAheadBeyondLastByte;
  /* 0x0048 */ unsigned long ReadAheadSpinLock;
  /* 0x004c */ struct _LIST_ENTRY PrivateLinks;
  /* 0x0054 */ void* ReadAheadWorkItem;
} PRIVATE_CACHE_MAP, *PPRIVATE_CACHE_MAP; /* size: 0x0058 */

typedef struct _SHARED_CACHE_MAP
{
  /* 0x0000 */ short NodeTypeCode;
  /* 0x0002 */ short NodeByteSize;
  /* 0x0004 */ unsigned long OpenCount;
  /* 0x0008 */ union _LARGE_INTEGER FileSize;
  /* 0x0010 */ struct _LIST_ENTRY BcbList;
  /* 0x0018 */ union _LARGE_INTEGER SectionSize;
  /* 0x0020 */ union _LARGE_INTEGER ValidDataLength;
  /* 0x0028 */ union _LARGE_INTEGER ValidDataGoal;
  /* 0x0030 */ struct _VACB* InitialVacbs[4];
  /* 0x0040 */ struct _VACB** Vacbs;
  /* 0x0044 */ struct _EX_FAST_REF FileObjectFastRef;
  /* 0x0048 */ struct _EX_PUSH_LOCK VacbLock;
  /* 0x004c */ unsigned long DirtyPages;
  /* 0x0050 */ struct _LIST_ENTRY LoggedStreamLinks;
  /* 0x0058 */ struct _LIST_ENTRY SharedCacheMapLinks;
  /* 0x0060 */ unsigned long Flags;
  /* 0x0064 */ long Status;
  /* 0x0068 */ struct _MBCB* Mbcb;
  /* 0x006c */ void* Section;
  /* 0x0070 */ struct _KEVENT* CreateEvent;
  /* 0x0074 */ struct _KEVENT* WaitOnActiveCount;
  /* 0x0078 */ unsigned long PagesToWrite;
  /* 0x0080 */ __int64 BeyondLastFlush;
  /* 0x0088 */ struct _CACHE_MANAGER_CALLBACKS* Callbacks;
  /* 0x008c */ void* LazyWriteContext;
  /* 0x0090 */ struct _LIST_ENTRY PrivateList;
  /* 0x0098 */ void* LogHandle;
  /* 0x009c */ void* FlushToLsnRoutine /* function */;
  /* 0x00a0 */ unsigned long DirtyPageThreshold;
  /* 0x00a4 */ unsigned long LazyWritePassCount;
  /* 0x00a8 */ struct _CACHE_UNINITIALIZE_EVENT* UninitializeEvent;
  /* 0x00ac */ struct _KGUARDED_MUTEX BcbLock;
  /* 0x00d0 */ union _LARGE_INTEGER LastUnmapBehindOffset;
  /* 0x00d8 */ struct _KEVENT Event;
  /* 0x00e8 */ union _LARGE_INTEGER HighWaterMappingOffset;
  /* 0x00f0 */ struct _PRIVATE_CACHE_MAP PrivateCacheMap;
  /* 0x0148 */ void* WriteBehindWorkQueueEntry;
  /* 0x014c */ struct _VOLUME_CACHE_MAP* VolumeCacheMap;
  /* 0x0150 */ unsigned long ProcImagePathHash;
  /* 0x0154 */ unsigned long WritesInProgress;
  /* 0x0158 */ unsigned long PipelinedReadAheadSize;
  /* 0x015c */ long __PADDING__[1];
} SHARED_CACHE_MAP, *PSHARED_CACHE_MAP; /* size: 0x0160 */

