typedef struct _HEAP_SUBALLOCATOR_CALLBACKS
{
  /* 0x0000 */ unsigned long Allocate;
  /* 0x0004 */ unsigned long Free;
  /* 0x0008 */ unsigned long Commit;
  /* 0x000c */ unsigned long Decommit;
  /* 0x0010 */ unsigned long ExtendContext;
} HEAP_SUBALLOCATOR_CALLBACKS, *PHEAP_SUBALLOCATOR_CALLBACKS; /* size: 0x0014 */

typedef struct _RTL_HP_LFH_CONFIG
{
  /* 0x0000 */ unsigned long MaxBlockSize;
  /* 0x0004 */ unsigned long MaxSubsegmentSize;
  struct // _TAG_UNNAMED_35
  {
    /* 0x0008 */ unsigned long ForceEnable : 1; /* bit position: 0 */
  } /* size: 0x0004 */ Flags;
} RTL_HP_LFH_CONFIG, *PRTL_HP_LFH_CONFIG; /* size: 0x000c */

typedef struct _HEAP_LFH_SUBSEGMENT_STAT
{
  /* 0x0000 */ unsigned char Index;
  /* 0x0001 */ unsigned char Count;
} HEAP_LFH_SUBSEGMENT_STAT, *PHEAP_LFH_SUBSEGMENT_STAT; /* size: 0x0002 */

typedef union _HEAP_LFH_SUBSEGMENT_STATS
{
  union
  {
    /* 0x0000 */ struct _HEAP_LFH_SUBSEGMENT_STAT Buckets[2];
    /* 0x0000 */ void* AllStats;
  }; /* size: 0x0004 */
} HEAP_LFH_SUBSEGMENT_STATS, *PHEAP_LFH_SUBSEGMENT_STATS; /* size: 0x0004 */

typedef struct _HEAP_LFH_CONTEXT
{
  /* 0x0000 */ void* BackendCtx;
  /* 0x0004 */ struct _HEAP_SUBALLOCATOR_CALLBACKS Callbacks;
  /* 0x0018 */ unsigned char MaxAffinity;
  /* 0x001c */ const unsigned char* AffinityModArray;
  /* 0x0020 */ unsigned char LockType;
  /* 0x0024 */ struct _HEAP_RUNTIME_MEMORY_STATS* MemStats;
  /* 0x0028 */ struct _RTL_HP_LFH_CONFIG Config;
  /* 0x0034 */ unsigned long SubsegmentCreationLock;
  /* 0x0038 */ union _HEAP_LFH_SUBSEGMENT_STATS BucketStats;
  /* 0x003c */ struct _HEAP_LFH_BUCKET* Buckets[129];
} HEAP_LFH_CONTEXT, *PHEAP_LFH_CONTEXT; /* size: 0x0240 */

