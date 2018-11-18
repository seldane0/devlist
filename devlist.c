#include <stdio.h>
#include <endian.h>
#include <infiniband/verbs.h>

int
main(int argc, char *argv[])
{
	struct ibv_device **dev_list;
	int i, n;

	dev_list = ibv_get_device_list(&n);
	if (dev_list == NULL) {
		printf ("dev list is empty.\n");
		return -1;
	}

	for (i=0; i < n; i++) {
		printf ("%d: %s %llx\n", i,
			ibv_get_device_name(dev_list[i]),
			(unsigned long long) be64toh(ibv_get_device_guid(dev_list[i])));
	}
	return 0;
}
