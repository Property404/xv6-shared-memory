#include "param.h"
#include "types.h"
#include "defs.h"
#include "mmu.h"
#include "proc.h"
#include "x86.h"
#include "mmu.h"
#include "proc.h"
#include "elf.h"
int shmem_count[SHMEM_PAGES];
void *shmem_addr[SHMEM_PAGES];

// "Officially" add to process and deal with shmem_count
void add_shpage_to_proc(struct proc* p, int pageno, void* la)
{
	shmem_count[pageno]++;
	p->shpages_quantity++;
	p->shpages[pageno] = la;
}

// "Officially" remove all shpages from process and deal with shmem_count
void rm_shpage_from_proc(struct proc* p)
{
	for(int i=0;i<SHMEM_PAGES;i++)
	{
		if (p->shpages[i] != NULL)
		{
			p->shpages[i] = NULL;
			shmem_count[i]--;
		}
	}
	p->shpages_quantity = 0;
}

void shmeminit(void)
{
	for(int i=0; i < SHMEM_PAGES; i++)
	{
		shmem_count[i] = 0;
		if((shmem_addr[i] = kalloc())==0)
		{
			panic("shmeminit failed");
		}
		cprintf("shmem_addr[%d]=%x\n", i, (unsigned int) shmem_addr[i]);
	}
}

void* shmem_access(struct proc* p, int pageno)
{
	// Invalid page number
	if(pageno>=SHMEM_PAGES || pageno<0) 
	{
		cprintf("shmem page number invalid\n");
		return NULL;
	}

	// Get physical address
	void* mem = shmem_addr[pageno];
	if(mem == NULL)
	{
		cprintf("shmem was not properly initialized properly before calling shmem_access\n");
		return NULL;
	}

	// Get page directory
	pde_t* pgdir;
	pgdir = p->pgdir;
	if(pgdir == 0)
	{
		cprintf("shmem_access(): pgdir == NULL\n");
		return NULL;
	}

	// Get virtual/linear address
	void* virtual_address = PGROUNDDOWN(USERTOP - (p->shpages_quantity+1)*PGSIZE);
	if((void*)(p->sz) > virtual_address)
		return NULL;

	if(-1 == mappages(
			pgdir,			// Page directory?!?!?
			virtual_address,
			PGSIZE,		// Size
			PADDR(mem), // Physical address
			PTE_W|PTE_U // Flags
			))
	{
		cprintf("mappages() failed in shmem_access\n");
		return NULL;
	}

	add_shpage_to_proc(p, pageno, virtual_address);
	return virtual_address;
}
